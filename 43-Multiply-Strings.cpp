class Solution {
public:
    void fill(int *array, string &num) {
        for (int i = 0; i < num.size(); ++i) {
            array[i] = num[i] - '0';
        }
    }

    string multiply(string num1, string num2) {
        char c[110 * 2 + 5] = { 0 };
        int a[110], b[110];
        int matrix[110 + 5][110 + 5];
        
        fill(a, num1);
        fill(b, num2);
        
        int matrix_row = num2.size(), matrix_column = num1.size() + 1;
        for (int i = num2.size()-1; i >= 0; --i) {
            int carry = 0;
            for (int j = num1.size()-1; j >= 0; --j) {
                int tmp = a[j] * b[i] + carry;
                matrix[matrix_row - 1 - i][j+1] = tmp % 10;
                carry = tmp / 10;
            }
            matrix[matrix_row - 1 - i][0] = carry;
            std::cout << std::endl;
        }
        
        int carry = 0, length = matrix_row + matrix_column;
        for (int i = length-2; i >= 0; --i) {
            int row = i < matrix_row-1 ? matrix_row - i - 1 : 0;
            int column = i < matrix_row-1  ? 0 : i - matrix_row + 1;
            int sum = carry;
            while (row < matrix_row && column < matrix_column) {
                sum += matrix[row++][column++];
            }
            c[i+1] = (sum % 10) + '0';
            carry = sum / 10;
        }
        c[0] = carry + '0';
        
        for (int i = 0; i < length; ++i) {
            if (c[i] == '0') continue;
            return string(c + i);
        } 
        return "0";
    }
};
