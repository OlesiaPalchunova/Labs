#include <bits/stdc++.h>
#include <cmath>
#include <string>

using namespace std;

class BigInt{
	string digits;
public:

	BigInt();
	BigInt(string);
	BigInt(int);
	BigInt(BigInt &);
    ~BigInt() = default;

    BigInt& operator=(const BigInt&);
    BigInt& operator~();

    BigInt& operator++();
    BigInt operator++(int temp);
    BigInt& operator--();
    BigInt operator--(int temp);

    BigInt& operator+=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator/=(const BigInt&);

    friend bool operator==(const BigInt&, const BigInt&);
    friend bool operator!=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);

    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);
    friend BigInt operator^(const BigInt &, const BigInt &);
    friend BigInt operator&(const BigInt &, const BigInt &);
    friend BigInt operator|(const BigInt &, const BigInt &);
    friend BigInt operator%(const BigInt &, const BigInt &);

    BigInt& operator^=(const BigInt&);
    BigInt& operator%=(const BigInt&);
    BigInt& operator&=(const BigInt&);
    BigInt& operator|=(const BigInt&);

    BigInt operator+();  // unary +
    BigInt operator-();  // unary -

    operator int() const;
    operator std::string() const;
    friend size_t size(const BigInt &);

    friend ostream &operator<<(ostream &,const BigInt &);
};

size_t size(const BigInt& a){
    return a.digits.size()*8;
}

BigInt::operator std::string() const{
    string a;
    BigInt b;
    b = *this;
    int sign = 1;
    if (b.digits[b.digits.size()-1] < 0) {
        sign = -1;
        b.digits[b.digits.size()-1] *= -1;
    }
    for (int i = 0; i < digits.size(); i++){
        if ((short)b.digits[i] == 0) a.insert(0, "0");
        if ((short)b.digits[i] == 1) a.insert(0, "1");
        if ((short)b.digits[i] == 2) a.insert(0, "2");
        if ((short)b.digits[i] == 3) a.insert(0, "3");
        if ((short)b.digits[i] == 4) a.insert(0, "4");
        if ((short)b.digits[i] == 5) a.insert(0, "5");
        if ((short)b.digits[i] == 6) a.insert(0, "6");
        if ((short)b.digits[i] == 7) a.insert(0, "7");
        if ((short)b.digits[i] == 8) a.insert(0, "8");
        if ((short)b.digits[i] == 9) a.insert(0, "9");
    }
    if (sign == -1) a.insert(0, "-");
    return a;
}

BigInt::operator int() const{
    int  res = 0;
    for (int i = digits.size()-1; i >= 0; i--){
        res *= 10;
        res += digits[i];
    }
    return res;
}


BigInt::BigInt(string s){
	digits = "";
	int n = s.size();
	for (int i = n - 1; i >= 0;i--){
		if(!isdigit(s[i]) && s[i] != '-')
			throw("ERROR");
        if (s[i] == '-') {
            digits[digits.size() - 1] *= -1;
            break;
        }
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(){
	digits = {'\0'};
}
BigInt::BigInt(int a){
	digits = "";
    int flag = 0;
    if (a < 0) {
        flag = 1;
        a *= -1;
    }
    if (a == 0) digits.push_back(0);
    while (a > 0){
        digits.push_back(a % 10);
        a = a / 10;
    }
    if (flag == 1) digits[digits.size()-1] *= -1;
}
BigInt::BigInt(BigInt & a){
	digits = a.digits;
}

bool operator==(const BigInt& a, const BigInt& b){
    return a.digits == b.digits ? true : false;
}

bool operator!=(const BigInt& a, const BigInt& b){
    return a.digits != b.digits;
}

bool operator<(const BigInt& a, const BigInt& b){
    if (a.digits == b.digits) return false;
    int la = a.digits.size() - 1, lb = b.digits.size() - 1;
    if (a.digits[la] == 0 && b.digits[lb] > 0) return true;
    if (a.digits[la] == 0 && b.digits[lb] < 0) return false;
    if (a.digits[la] < 0 && b.digits[lb] == 0) return true;
    if (a.digits[la] > 0 && b.digits[lb] == 0) return false;
    if (a.digits[la] < 0 && b.digits[lb] > 0) return true;
    if (a.digits[la] > 0 && b.digits[lb] < 0) return false;
    if (a.digits.size() < b.digits.size() && a.digits[la] >= 0) return true;
    if (a.digits.size() < b.digits.size() && a.digits[la] < 0) return false;
    if (a.digits.size() > b.digits.size() && a.digits[la] >= 0) return false;
    if (a.digits.size() > b.digits.size() && a.digits[la] < 0) return true;
    int i = a.digits.size() - 1;
    while (a.digits[i] == b.digits[i]) i--;
    if (a.digits[i] < b.digits[i] && a.digits[la] > 0) return true;
    if (a.digits[i] > b.digits[i] && a.digits[la] > 0) return false;
    if (a.digits[i] < b.digits[i] && a.digits[la] < 0) return false;
    if (a.digits[i] > b.digits[i] && a.digits[la] < 0) return true;
}

bool operator>(const BigInt& a, const BigInt& b){
    return b < a ? true : false;
}

bool operator<=(const BigInt& a, const BigInt& b){
    return (a > b) ? false : true;
}

bool operator>=(const BigInt& a, const BigInt& b){
    return (a < b) ? false : true;
}

BigInt &BigInt::operator=(const BigInt &a){
    digits = a.digits;
    return *this;
}

BigInt &BigInt::operator++(){
    int i = 0;
    if (digits[digits.size() - 1] < 0){
        digits[digits.size() - 1]*= -1;
        --*this;
        digits[digits.size() - 1]*= -1;
        return *this;
    }
    while (digits[i] == 9) {
        digits[i] = 0;
        i++;
    }
    if (i == digits.size()) {
        digits.push_back(0);
        digits[i] = 1;
    } else digits[i]++;
    return *this;
}

BigInt BigInt::operator++(int temp){
    BigInt a;
    a = *this;
    ++(*this);
    return a;
}

BigInt &BigInt::operator+=(const BigInt& a){
    BigInt b, zero(0), minus(-1);
    b.digits = a.digits;
    if (a == zero) return *this;
    if (*this == zero) {
        *this = a;
        return *this;
    }
    if (*this > zero && a < zero) {
        *this -= a*minus;
        return *this;
    }
    if (*this < zero && a > zero) {
        b = *this;
        b *= minus;
        *this = a;
        *this -= b;
        return *this;
    }
    int sign = 1;
    if (*this < zero && b < zero){
        *this *= minus;
        b *= minus;
        sign = minus;
        if (*this < b){
            BigInt c;
            c = *this;
            *this = b;
            b = c;
        }
    }else if (*this < b){
        b = *this;
        *this = a;
    }
    int i;
    for (i = 0; i < b.digits.size(); i++){
        digits[i] += b.digits[i];
        if (digits[i] > 9 && i != digits.size()-1) {
            digits[i] -= 10;
            digits[i+1]++;
        }
    }
    while (digits[i] > 9) {
        digits[i] -= 10;
        digits[i+1]++;
        i++;
    }
    if (digits[digits.size()-1] == 0) {
        digits[digits.size()-1] %= 10;
        digits.push_back(1);
    }
    digits[digits.size() - 1] *= sign;
    return *this;
}

BigInt &BigInt::operator--(){
    int i;
    if (digits[digits.size()-1] < 0){
        digits[digits.size()-1] *= -1;
        ++*this;
        digits[digits.size()-1] *= -1;
        return *this;
    }
    if (digits[0] == 0 && digits.size() == 1) throw UNDERFLOW;
    for (i = 0; digits[i] == 0 && i < digits.size(); i++){
        digits[i] = 9;
    }
    digits[i]--;
    if (digits[digits.size()-1] == 0 && digits.size() != 1) digits.erase(digits.size() - 1);
    return *this;
}

BigInt BigInt::operator--(int temp){
    BigInt a;
    a = *this;
    --(*this);
    return a;
}

BigInt &BigInt::operator-=(const BigInt& a){
    BigInt b, zero(0), minus(-1);
    b.digits = a.digits;
    int flag = 1;
    if (a == *this){
        *this = zero;
        return *this;
    }
    if (*this <= zero && b >= zero){
        *this *= minus;
        *this += b;
        *this *= minus;
        return *this;
    }
    if (*this >= zero && b <= zero){
        b *= minus;
        *this += b;
        return *this;
    }
    if (*this <= zero && b <= zero){
        *this *= minus;
        b = *this;
        *this = a*minus;
        if (*this < b){
            BigInt c;
            c = *this;
            *this = b;
            b = c;
            flag = -1;
        }
    }
    if (*this < b){
        b = *this;
        *this = a;
        flag = -1;
        cout << *this << endl;
    }
    int i;
    for (i = 0; i < b.digits.size(); i++){
        digits[i] -= b.digits[i];
        if (digits[i] < 0){
            digits[i] += 10;
            digits[i+1] -= 1;
        }
    }
    while (digits[i] < 0){
        digits[i] += 10;
        digits[i+1]--;
        i++;
    }
    i = digits.size()-1;
    while (digits[i] == 0) digits.erase(i--);
    *this *= flag;
    return *this;
}

BigInt &BigInt::operator*=(const BigInt& a){
    int mind = 0;
    BigInt t1, t2, temp;
    t1 = 0;
    t2.digits.erase(0);
    BigInt b, zero(0);
    b.digits = a.digits;
    if (*this == zero || a == zero) {
        *this = zero;
        return *this;
    }
    int sign = 1;
    if (*this < zero && b > zero) {
        digits[digits.size() - 1] *= -1;
        sign = -1;
    }
    if (*this > zero && b < zero){
        b.digits[b.digits.size() - 1] *= -1;
        sign = -1;
    }
    if (*this < zero && b < zero){
        digits[digits.size() - 1] *= -1;
        b.digits[b.digits.size() - 1] *= -1;
    }
    for (int i = 0; i < b.digits.size(); i++){
        if (b.digits[i] == 0){
            t2 = temp;
            temp.digits.push_back(0);
            continue;
        }
        for (int j = 0; j < digits.size(); j++){
            int num = digits[j] * b.digits[i] + mind;
            if (num > 9) {
                mind = num / 10;
                num %= 10;
            } else mind = 0;
            t2.digits.push_back(num);
        }
        if (mind != 0) t2.digits.push_back(mind);
        t1 += t2;
        t2 = temp;
        temp.digits.push_back(0);
        mind = 0;
    }
    digits = t1.digits;
    digits[digits.size()-1] *= sign;
    return *this;
}

BigInt &BigInt::operator/=(const BigInt& a){
    BigInt b, zero(0);
    b.digits = a.digits;
    int sign = 1;
    if (a == zero) throw runtime_error("Math error: Attempted to divide by Zero\n");;
    if (*this == zero) return *this;
    if (*this < zero && b > zero){
        digits[digits.size()-1] *= -1;
        sign = -1;
    }
    if (*this > zero && b < zero){
        b.digits[b.digits.size()-1] *= -1;
        sign = -1;
    }
    if (*this < zero && b < zero){
        digits[digits.size()-1] *= -1;
        b.digits[b.digits.size()-1] *= -1;
    }
    BigInt t1(0), t2(0);
    if (*this < b) {
        *this = 0;
        return *this;
    }
    for (int j = digits.size() -1; j >= 0; j--){
        t2 *= 10;
        t2 += digits[j];
        if (t2 == zero) {
            t1 *= 10;
            continue;
        }
        while (t2 < b) {
            j--;
            if (j < 0) break;
            t2 *= 10;
            t2 += digits[j];
        }
        BigInt i(0);
        while (t2 >= b*i) i++;
        i--;
        t1 *= 10;
        t1 += i;
        t2 -= b*i;
    }
    *this = t1;
    digits[digits.size()-1] *= sign;
    return *this;
}

BigInt operator+(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

BigInt operator-(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

BigInt operator*(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

BigInt operator/(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}


BigInt &BigInt::operator%=(const BigInt& a){
    BigInt b;
    b.digits = a.digits;
    int sign = 1;
    if (b.digits[b.digits.size() - 1] < 0) b.digits[b.digits.size() - 1] *= -1;
    if (digits[digits.size() - 1] < 0) {
        digits[digits.size() - 1] *= -1;
        sign = -1;
    }
    *this -= (*this / b) * b;
    *this *= sign;
    return *this;
}

BigInt operator^(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp ^= b;
    return temp;
}

BigInt operator%(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}

BigInt operator&(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp &= b;
    return temp;
}

BigInt operator|(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp |= b;
    return temp;
}

ostream &operator<<(ostream &out,const BigInt &a){
    if (a.digits[0] == '-') cout << '-';
    for (int i = a.digits.size() - 1; i >= 0;i--)
        cout << (short)a.digits[i];
    return cout;
}

BigInt &BigInt::operator|=(const BigInt& a){
    BigInt b, t(0), two(2), one(1), zero(0);
    b.digits = a.digits;
    if (digits[digits.size() - 1] >= 0 && a.digits[a.digits.size() - 1] < 0){
        b.digits = digits;
        digits = a.digits;
    }
    if (digits[digits.size() - 1] < 0  && b.digits[b.digits.size() - 1] >= 0){
        BigInt temp = *this;
        temp *= -1;
        temp -= 1;
        int dec = 1;
        while (b != t){
            if (temp % two == one &&  b % two == zero) {
                *this += dec;
            }
            dec *= 2;
            b /= 2;
            temp /= 2;
        }
        return *this;
    }
    if (digits[digits.size() - 1] < 0  && a.digits[a.digits.size() - 1] < 0){
        BigInt temp = *this;
        temp *= -1;
        temp -= 1;
        b.digits = a.digits;
        b *= -1;
        b -= 1;
        int dec = 1;
        while (b != t){
            if (temp % two == one &&  b % two == zero) *this += dec;
            dec *= 2;
            b /= 2;
            temp /= 2;
        }
        return *this;
    }
    if (a > *this) {
        b.digits = digits;
        digits = a.digits;
    }
    BigInt temp;
    temp.digits = digits;
    int i = 0, j = 1;
    while (b.digits.size() != 0){
        if (temp.digits[i] % 2 == 0 && b.digits[i] % 2 == 1) {
            *this += j;
        }
        if (b.digits.size() == 1 && b.digits[0] == 0) break;
        b /= 2;
        temp /= 2;
        j *= 2;
    }
    return *this;
} 

BigInt &BigInt::operator&=(const BigInt& a){
    BigInt b, t(0), zero(0), one(1), two(2);
    b.digits = a.digits;
    if (digits[digits.size() - 1] < 0 && a.digits[a.digits.size() - 1] >= 0){
        b.digits = digits;
        digits = a.digits;
    }
    if (digits[digits.size() - 1] >= 0  && b.digits[b.digits.size() - 1] < 0){
        BigInt temp = *this;
        b *= -1;
        b -= 1;
        int dec = 1;
        while (b != t){ 
            if (temp % two == one &&  b % two == one) {
                *this -= dec;
            }
            dec *= 2;
            b /= 2;
            temp /= 2;
        }
        return *this;
    }
    if (digits[digits.size() - 1] < 0  && b.digits[b.digits.size() - 1] < 0){
        BigInt temp = *this;
        temp *= -1;
        temp -= 1;
        b *= -1;
        b -= 1;
        int dec = 1;
        while (b != t){
            if (temp % two == zero &&  b % two == one) *this -= dec;
            dec *= 2;
            b /= 2;
            temp /= 2;
        }
        return *this;
    }
    if (a < *this) {
        b.digits = digits;
        digits = a.digits;
    } else b.digits = a.digits;
    BigInt temp;
    temp.digits = digits;
    int i = 0, j = 1;
    while (b.digits.size() != 0){
        if (temp.digits[i] % 2 == 1 && b.digits[i] % 2 == 0) {
            *this -= j;
        }
        if (b.digits.size() == 1 && b.digits[0] == 0) break;
        b /= 2;
        temp /= 2;
        j *= 2;
    }
    return *this;
}

BigInt &BigInt::operator^=(const BigInt& a){
    BigInt b, t(0), zero(0), one(1), two(2);
    BigInt temp;
    b.digits = a.digits;
    if (digits[digits.size() - 1] >= 0 && a.digits[a.digits.size() - 1] < 0){
        cout << 666 << endl;
        b.digits = digits;
        digits = a.digits;
    }
    if (digits[digits.size() - 1] < 0  && b.digits[b.digits.size() - 1] >= 0){
        BigInt temp = *this;
        temp *= -1;
        temp -= 1;
        int dec = 1;
        while (b != t){ 
            if (temp % two == one &&  b % two == one) {
                *this += dec;
            }
            if (temp % two == zero &&  b % two == one) {
                *this -= dec;
            }
            dec *= 2;
            b /= 2;
            temp /= 2;
        }
        return *this;
    }
    if (digits[digits.size() - 1] < 0  && b.digits[b.digits.size() - 1] < 0){
        *this *= -1;
        *this -= 1;
        b *= -1;
        b -= 1;
    }
    if (b > *this) {
        BigInt c;
        c.digits = b.digits;
        b.digits = digits;
        digits = c.digits;
    }
    temp.digits = digits;
    int i = 0, j = 1;
    while (b != t){
        if (temp.digits[i] % 2 == 1 && b.digits[i] % 2 == 1) {
            *this -= j;
            temp.digits[i]--;
            b.digits[i]--;
        }
        else if (temp.digits[i] % 2 == 0 && b.digits[i] % 2 == 1) {
            *this += j;
            b.digits[i]--;
        } else if (temp.digits[i] % 2 == 1) temp.digits[i]--;
        b = operator/(b, 2);
        temp = operator/(temp, 2);
        j *= 2;
    }
    return *this;
}

BigInt &BigInt::operator~(){
    BigInt zero(0);
    if (*this >= zero){
        (*this)++;
        *this *= -1;
    } else {
        *this *= -1;
        (*this)--;
    }
    return *this;
}

BigInt BigInt::operator+() {
    return *this;
}

BigInt BigInt::operator-() {
    BigInt b = *this;
    b *= -1;
    return b;
}

int main()
{
	BigInt first("-1234567890");
    BigInt second(4);
    int t = size(first);
    cout << t << endl;
    return 0;
}
