#include "long_number.hpp"

using ga::LongNumber;
		
LongNumber::LongNumber() {
	this->sign = 1;
	this->length = 1;
	this->numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(int length, int sign) {
	this->length = length;
	this->sign = sign;
	this->numbers = new int[length]();
}

LongNumber::LongNumber(const char* const str) {
	length = get_length(str);
	int start_index = 0;
	if (str[0] == '-'){
		this->length -= 1;
		this->sign = 0;
		start_index = 1;
	} else {
		this->sign = 1;
	}
	this->numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[start_index++] - '0';
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	this->length = x.length;
	this->sign = x.sign;
	this->numbers = new int[length];
	for (int i = 0; i < this->length; i++) {
		this->numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	this->length = x.length;
	this->sign = x.sign;
	this->numbers = new int[length];
	for (int i = 0; i < this->length; i++) {
		this->numbers[i] = x.numbers[i];
	}
	x.length = 0;
	x.sign = 1;
	x.numbers = nullptr;
}

LongNumber::~LongNumber() {
	if (numbers != nullptr) {
		delete[] numbers;
	}
	this->numbers = nullptr;
}


LongNumber& LongNumber::operator = (const char* const str) {
	delete[] numbers;
	
	this->length = get_length(str);
	int start_index = 0;
	if (str[0] == '-'){
		this->length -= 1;
		this->sign = 0;
		start_index = 1;
	} else {
		this->sign = 1;
	}
	this->numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[start_index++] - '0';
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;
	
	this->length = x.length;
	this->sign = x.sign;
	delete[] numbers;
	this->numbers = new int[length];
	for (int i = 0; i < this->length; i++) {
		this->numbers[i] = x.numbers[i];
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	if (this == &x) return *this;
	
	this->length = x.length;
	this->sign = x.sign;
	delete[] numbers;
	this->numbers = new int[length];
	for (int i = 0; i < this->length; i++) {
		this->numbers[i] = x.numbers[i];
	}
	
	x.length = 0;
	x.sign = 1;
	x.numbers = nullptr;
	
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if ((this->length != x.length) || (this->sign != x.sign)) {
		return false;
	}
	for (int i = 0; i < this->length; i++) {
		if (this->numbers[i] != x.numbers[i]) return false;
	}
	
	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	if ((this->length != x.length) || (this->sign != x.sign)) {
		return true;
	}
	for (int i = 0; i < this->length; i++) {
		if (this->numbers[i] != x.numbers[i]) return true;
	}
	
	return false;
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (this->sign > x.sign) {
		return true;
	}
	
	if (this->sign == x.sign) {
		if (this->sign == 1) {
			if (this->length > x.length) {
				return true;
			} else if (this-> length < x.length) return false;
			
			for (int i = 0; i < this->length; i++) {
					if (this->numbers[i] > x.numbers[i]) return true;
			}
		}
		if (this->sign == 0) {
			if (this->length < x.length) {
				return true;
			} else if (this->length > x.length) return false;
			
			for (int i = 0; i < this->length; i++) {
					if (this->numbers[i] < x.numbers[i]) return true;
			}
		}
	}
	
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	if (*this != x && !(*this > x)) return true;
	
	return false;
}

void LongNumber::delete_zeros () {
		int i = 0;
		while (numbers[i] == 0 && i < length - 1) {
			i++;
		}
		int sub_len = length - i;
		int* new_numbers = new int [sub_len];
		int j = 0;
		while (i < length) {
			new_numbers[j] = numbers[i];
			i++;
			j++;
		}
		delete[] numbers;
		numbers = new_numbers;
		length = sub_len;
}		

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (sign != x.sign) {
		if (sign == 0) {
			LongNumber new_object = *this;
			new_object.sign = 1;
			LongNumber result1 = x - new_object;
			return result1;
		} else if (x.sign == 0) {
			LongNumber new_object = x;
			new_object.sign = 1;
			LongNumber result1 = 
			*this - new_object;
			return result1;
		}
	}
	int max_length;
	if (length >= x.length) {
		max_length = length + 1;
	} else {
		max_length = x.length + 1;
	}
	LongNumber result2(max_length, sign);
	int i = length - 1;
	int j = x.length - 1;
	int k = max_length - 1;
	while (i >= 0 && j >= 0) {
		result2.numbers[k-1] += (numbers[i] + x.numbers[j] + result2.numbers[k])/10;
		result2.numbers[k] = (numbers[i] + x.numbers[j] + result2.numbers[k])%10;
		i--;
		j--;
		k--;
	}
	
	while (i >= 0) {
		result2.numbers[k-1] += (numbers[i] + result2.numbers[k])/10;
		result2.numbers[k] = (numbers[i] + result2.numbers[k])%10;
		i--;
		k--;
	}
	
	while (j >= 0) {
		result2.numbers[k-1] += (x.numbers[j] + result2.numbers[k])/10;
		result2.numbers[k] = (x.numbers[j] + result2.numbers[k])%10;
		j--;
		k--;
	}
	result2.delete_zeros();
	return result2;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	if (sign != x.sign) {
		if (sign == 0) {
			LongNumber new_object = x;
			new_object.sign = 0;
			LongNumber result1 = new_object + *this;
			return result1;
		} else if (x.sign == 0) {
			LongNumber new_object = x;
			new_object.sign = 1;
			LongNumber result1 = new_object + *this;
			return result1;
		}
	}
	if (sign == 0) {
		if (*this > x) {
			LongNumber result1;
			result1 = x - *this;
			result1.sign = 1;
			return result1;
		} 
	} else {
		if (*this < x) {
			LongNumber result1;
			result1 = x - *this;
			result1.sign = 0;
			return result1;
		}
	}
	int max_length;
	if (length >= x.length) {
		max_length = length + 1;
	} else {
		max_length = x.length + 1;
	}
	LongNumber result2 (max_length, sign);
	int i = length - 1;
	int j = x.length - 1;
	int k = max_length - 1;
	while (j >=0) {
		result2.numbers[k] += (numbers[i] - x.numbers[j]);
		if (result2.numbers[k] < 0) {
			result2.numbers[k] +=10;
			result2.numbers[k-1] -= 1;
		}
		i--;
		j--;
		k--;
	}
	while (i >= 0) {
		result2.numbers[k] += numbers[i];
		i--;
	}
	result2.delete_zeros();
	return result2;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	int len = length + x.length;
	LongNumber result(len, int(sign == x.sign));
	for (int i = length; i >= 0; i--) {
		for (int j = x.length; j >= 0; j--) {
			result.numbers[i+j] += numbers[i] * x.numbers[j];
		}
	}
	for (int k = len; k >= 0; k--) {
			result.numbers[k-1] += (result.numbers[k] / 10);
			result.numbers[k] = (result.numbers[k] % 10);
	}
	result.delete_zeros();
	return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	if (x.length > length) {
		LongNumber result ("0");
		return result;
	}
	int max_length;
	if (length >= x.length) {
		max_length = length + 1;
	} else {
		max_length = x.length + 1;
	}
	LongNumber result(max_length, int(sign == x.sign));
	LongNumber sub(1, 1);

	for (int i = 0; i < length; i++) {

		LongNumber temp(sub.length + 1, 1);

		for (int j = 0; j < sub.length; j++) {
			temp.numbers[j] = sub.numbers[j];
		}

		temp.numbers[sub.length] = numbers[i];
		temp.length = sub.length + 1;

		sub = temp;

		int n = 0;

		while (!(sub < x)) {
			sub = sub - x;
			n++;
		}

		sub.numbers[i] = n;
	}
	result.delete_zeros();
	return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	LongNumber result;
	result = *this - ((*this / x) * x);
	result.delete_zeros();
	return result;
}

bool LongNumber::is_negative() const noexcept {
	return this->sign == 0;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace ga {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == 0) {
			os << "-";
		}

		for (int i = 0; i < x.length; i++) {
			os << x.numbers[i];
		}

		return os;
	}
}
