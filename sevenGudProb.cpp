#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

//reverse a string
//using built in function
string reverseUsingAlgo(string s) {
    reverse(s.rbegin(), s.rend());
    return s;
}
//my meathod S(n) and O(n)
string getChar(string s, int i) {
    if (i == s.length()) return "";
    return getChar(s, i + 1) + s[i];
}
//apna clg method O(n2)
void reverseRec(string s) {
    if (s.length() == 0) {
        return;
    }
    string los = s.substr(1);
    reverseRec(los);
    cout << s[0];
}

//replace pi 
//my meathod O(n2)
string replacePi(string s, int  i) {
    if (i == s.length()) return s;
    if (s[i]=='p' & s[i+1] == 'i') {
        s.replace(i, 2, "3.14");
    }
    return replacePi(s, i+1);
}

//apna clg meathod
void replacepi(string s) {
    if (s.length() == 0) {
        return;
    }
    if (s[0] == 'p' & s[1] == 'i') {
        cout << "3.14";
        replacepi(s.substr(2));
    } else {
        cout << s[0];
    replacepi(s.substr(1));}
}

//tower of hanoi
void towerOfHanoi(int n, char s, char d, char h) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, s, h, d);
    cout << "move from " << s << " to " << d<<endl;
    towerOfHanoi(n - 1, h, d, s);
}
void callTowerOfHanoi(int n) {
    towerOfHanoi(n, 'S', 'D', 'H');
}

//remove duplicates from string
//my meathod
string removeDuplicate(string s, int i) {
    if (i == s.length()) return s;
    if (s[i] == s[i + 1]) {
        s.erase(i, 1);
        return removeDuplicate(s, i);
    }
    return removeDuplicate(s, ++i);
}

//apna clg meathod 
//return the first character plus the rest of the string if the first  charecter is not equal to the first char of the
//remaining string.
string removeDub(string s) {
    if (s.length() == 0)return "";

    string sleft = removeDub(s.substr(1));
    if (s[0] == sleft[0]) {
        return sleft;
    }
    return s[0] + sleft;
}
//move all x to end
string movex(string s) {
    if (s.length() == 0) {
        return s;
    }
    char ch = s[0];
    string lefts = movex(s.substr(1));
    if (ch == 'x'){
        return lefts +'x';
    }
    return ch + lefts;
}

//generate substring wit
//brute force 
void getSubs(string s) {
    int length = s.length();
    for (int i = 0;i < length;i++) {
        string s2 = "";
        for (int j = i;j < length;j++) {
            s2 += s[j];
            cout << s2 << endl;
        }
    }
}

//using stl
void getsubs(string s) {
    int l = s.length();
    for (int i = 0;i < l;i++) {
        for (int j = i;j < l;j++) {
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}

//get substring of 2^n times 
void getsubTwoN(string s) {
    int n = s.length();
    int tp = pow(2, n);
    for (int i = 0;i < tp; i++) {
        for (int j = 0;j <= n;j++) {
            if (i & (1 << j)) {
                cout << s[j];
            }
        }
        cout << endl;
    }

}

//get 2^n using recursion
void getsequence(string s, string ans) {
    if (s.length() == 0) {
        cout << ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    getsequence(ros, ans + ch);
    getsequence(ros, ans);
}

void substringWithAsci(string s,string ans) {
    if (s.length() == 0) {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int chi = ch;
    string sub = s.substr(1);
    //make three calls for dif values of ans to get the output
    substringWithAsci(sub, ans);
    substringWithAsci(sub, ans + ch);
    substringWithAsci(sub, ans + to_string(chi));
}
int main() {
    string s;
    cin >> s;
    substringWithAsci(s, "");
    return 0;
}