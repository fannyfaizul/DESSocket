#ifndef DES_H
#define DES_H

#include<bits/stdc++.h>
using namespace std;

vector<string> rkbin, rkhex;

string hexToASCII(string hex)
{
    // initialize the ASCII code string as empty.
    string ascii = "";
    for (size_t i = 0; i < hex.length(); i += 2)
    {
        // extract two characters from hex string
        string part = hex.substr(i, 2);
 
        // change it into base 16 and 
        // typecast as the character
        char ch = stoul(part, nullptr, 16);
 
        // add this char to final ASCII string
        ascii += ch;
    }
    return ascii;
}

string decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];
 
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        n = n / 16;
    }
 
    string ans = "";
 
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        ans += hexaDeciNum[j];
 
    return ans;
}

// Function to convert ASCII to HEX
string ASCIItoHEX(string ascii)
{
    // Initialize final String
    string hex = "";
 
    // Make a loop to iterate through
    // every character of ascii string
    for (int i = 0; i < ascii.length(); i++) {
        // Take a char from
        // position i of string
        char ch = ascii[i];
 
        // Cast char to integer and
        // find its ascii value
        int tmp = (int)ch;
 
        // Change this ascii value
        // integer to hexadecimal value
        string part = decToHexa(tmp);
 
        // Add this hexadecimal value
        // to final string.
        hex += part;
    }
    
    int len = hex.length();
    while(len%16){
        hex+= '0';
        len++;
    }
 
    // Return the final
    // string hex
    return hex;
}

string HexToBin(string hexdec)
{
      //Skips "0x" if present at beggining of Hex string
    size_t i = (hexdec[1] == 'x' || hexdec[1] == 'X')? 2 : 0;
    string ans = "";
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            ans += "0000"; break;
        case '1':
            ans += "0001"; break;
        case '2':
            ans += "0010"; break;
        case '3':
            ans += "0011"; break;
        case '4':
            ans += "0100"; break;
        case '5':
            ans += "0101"; break;
        case '6':
            ans += "0110"; break;
        case '7':
            ans += "0111"; break;
        case '8':
            ans += "1000"; break;
        case '9':
            ans += "1001"; break;
        case 'A':
        case 'a':
            ans += "1010"; break;
        case 'b':
        case 'B':
            ans += "1011"; break;
        case 'c':
        case 'C':
            ans += "1100"; break;
        case 'D':
        case 'd':
            ans += "1101"; break;
        case 'e':
        case 'E':
            ans += "1110"; break;
        case 'F':
        case 'f':
            ans += "1111"; break;
        case '.':
            ans += "."; break;
        case ' ':
            ans += " "; break;
            
        default:
            return "error kocak";
        }
        i++;
    }
    return ans;
}

string BinToHex(string binary) {
    binary = string(binary.length() % 4 ? 4 - binary.length() % 4 : 0, '0') + binary;
    unordered_map<string, char> hex_dict = {
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'},
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'},
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'}
    };
    string hexadecimal;
    for (size_t i = 0; i < binary.length(); i += 4) {
        string group = binary.substr(i, 4);
        hexadecimal += hex_dict[group];
    }
    return hexadecimal;
}

int initial_perm[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

int final_perm[] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25};
    
// Tabel S-Box
int sBox[8][4][16] = {
    // S-Box 1
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },

    // S-Box 2
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },

    // S-Box 3
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },

    // S-Box 4
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },

    // S-Box 5
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },

    // S-Box 6
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 6, 1, 7, 13, 8, 14, 13}
    },

    // S-Box 7
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },

    // S-Box 8
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
};

int exp_d[] = {32, 1, 2, 3, 4, 5, 4, 5,
         6, 7, 8, 9, 8, 9, 10, 11,
         12, 13, 12, 13, 14, 15, 16, 17,
         16, 17, 18, 19, 20, 21, 20, 21,
         22, 23, 24, 25, 24, 25, 26, 27,
         28, 29, 28, 29, 30, 31, 32, 1};
         
// parity bit drop table
int keyp[] = {57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4};

// Number of bit shifts
int shift_table[] = {1, 1, 2, 2,
               2, 2, 2, 2,
               1, 2, 2, 2,
               2, 2, 2, 1};
 
// Key- Compression Table : Compression of key from 56 bits to 48 bits
int key_comp[] = {14, 17, 11, 24, 1, 5,
            3, 28, 15, 6, 21, 10,
            23, 19, 12, 4, 26, 8,
            16, 7, 27, 20, 13, 2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32};
 
// Permute function to rearrange the bits
string permute(string k, int arr[], int n){
    string permutation = "";
    for(int i=0;i<n;i++)
        permutation += k[arr[i] - 1];
    return permutation;
}
    
//  shifting the bits towards left by nth shifts
string cshift_left(string k, int nth_shifts){
    return k.substr(k.find(k)+nth_shifts) + k.substr(k.find(k),nth_shifts);  
}

int binaryToDecimal(string n) 
{ 
    uint dec_num = 0 ; 
    int power = 0; 
    for(int i=0;i<n.length();i++){
        if(n[n.length()-i-1] == '1') dec_num += (1 << power);
        power++;
    }
    return dec_num ; 
} 

string DecimalToBinary(int num) 
{ 
    string str; 
    // cout << num;
      while(num){ 
      if(num & 1) // 1 
        str+='1'; 
      else // 0 
        str+='0'; 
      num>>=1; // Right Shift by 1   
    }     
    // cout <<" " << str << endl;
    reverse(str.begin(), str.end());
    int len = str.length();
    if(len%4 != 0 || len == 0){
        int div = len/4;
        int counter = (4*(div+1)) - len;
        while(counter--)
            str = '0' + str;
    }
    return str;
} 

string xor_string(string a, string b){
    string ans;
    for(int i=0;i<a.length();i++){
        if(a[i] == b[i]) ans += "0";
        else ans += "1";
    }
    return ans;
}

// Straight Permutation Table
int per[] = {16,  7, 20, 21,
       29, 12, 28, 17,
       1, 15, 23, 26,
       5, 18, 31, 10,
       2,  8, 24, 14,
       32, 27,  3,  9,
       19, 13, 30,  6,
       22, 11,  4, 25};
       
string encrypt(string pt){
    pt = HexToBin(pt);
 
    // Initial Permutation
    pt = permute(pt, initial_perm, 64);
    // cout << "After initial permutation: " << BinToHex(pt) << endl;
 
    //splitting
    string left = pt.substr(0,32);
    string right = pt.substr(pt.find(left)+32);
    
    for(int i=0;i<16;i++){
        // Expansion D-Box: Expanding the 32 bits data into 48 bits
        string right_expanded = permute(right, exp_d, 48);
        
        // XOR RoundKey and right_expanded
        string xor_x = xor_string(right_expanded,rkbin[i]);
        
        // S-boxex: substituting the value from s-box table by calculating row and column
        string sbox_str;
        for(int j=0;j<8;j++){
            int row = binaryToDecimal(xor_x.substr(xor_x.find(xor_x)+(j*6),1)+xor_x.substr(xor_x.find(xor_x)+(j*6+5),1));
            int col = binaryToDecimal(xor_x.substr(xor_x.find(xor_x)+(j*6+1),1)+xor_x.substr(xor_x.find(xor_x)+(j*6+2),1)+xor_x.substr(xor_x.find(xor_x)+(j*6+3),1)+xor_x.substr(xor_x.find(xor_x)+(j*6+4),1));
            int val = sBox[j][row][col];
            sbox_str += DecimalToBinary(val);
            // cout << "value " << val << endl;
            // cout << "value " << DecimalToBinary(val) << endl;
            // cout << "testing " << j << " " << row << " " << col << " " << val << endl;
            // cout << "testing " << xor_x.substr(xor_x.find(xor_x)+(j*6),1) << " " << xor_x.substr(xor_x.find(xor_x)+(j*6+5),1) << " " << row << endl;
        }
        // Straight D-box: After substituting rearranging the bits
        // cout << "Testing " << sbox_str << endl;
        sbox_str = permute(sbox_str, per, 32);
        // XOR left and sbox_str
        string result = xor_string(left, sbox_str);
        left = result;
        
        // Swapper
        if(i != 15){
            string temp = right;
            right = result;
            left = temp;
        }

               
        
        // cout << "Round " << i+1 << ": " << BinToHex(left) << " " << BinToHex(right) << " " << rkhex[i] << endl;
        // printf("Round %d %s %s %s\n", i+1, BinToHex(left), BinToHex(right), rkhex[i]);
    }
    // Combination
    string combine = left + right;
 
    // Final permutation: final rearranging of bits to get cipher text
    string cipher_text = permute(combine, final_perm, 64);
    return cipher_text;
}

string encryptor(){
    string msg;
    cout << "Masukkan kata yang ingin dienkripsi: \n";
    getline(cin, msg);
    string ptext = ASCIItoHEX(msg);
    // string ptext = "123456ABCD132536";
    string key = "AABB09182736CCDD";
    key = HexToBin(key);
    
    key = permute(key, keyp, 56);
    //splitting
    string left = key.substr(0,28);
    string right = key.substr(key.find(left)+28);
    
    //gabungan
    string fullstr;
    for(int i = 0;i<16;i++){
        left = cshift_left(left, shift_table[i]);
        right = cshift_left(right, shift_table[i]);
        
        fullstr = left+right;
        
        // Compression of key from 56 to 48 bits
        string round_key = permute(fullstr, key_comp, 48);
        
        rkbin.push_back(round_key);
        rkhex.push_back(BinToHex(round_key));
    }
    cout << "Encryption" << endl;
    int len = ptext.length();
    string cipher_text;
    for(int i=0;i<(len/16);i++){
        cipher_text += BinToHex(encrypt(ptext.substr(i*16, 16)));
    }
    // string cipher_text = BinToHex(encrypt(ptext));
    cout << "Cipher Text : " << cipher_text << endl;
    return cipher_text;
}

string decryptor(string cipher_text){
    int len = cipher_text.length();
    reverse(rkbin.begin(), rkbin.end());
    reverse(rkhex.begin(), rkhex.end());
    string plain_text;
    for(int i=0;i<(len/16);i++){
        plain_text += BinToHex(encrypt(cipher_text.substr(i*16, 16)));
    }
    // cout << "hexadecimal Text : " << plain_text << endl;
    plain_text = hexToASCII(plain_text); 
    // string plain_text = BinToHex(encrypt(cipher_text));
    cout << "Plain Text : " << plain_text << endl;
    return plain_text;
}


#endif
int main(){
    string cipher_text = encryptor();
    decryptor(cipher_text);
    return 0;
}

