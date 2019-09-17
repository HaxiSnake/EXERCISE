
class Solution {
public:
    bool isNumeric(char* str) {
        // ��Ƿ��š�С���㡢e�Ƿ���ֹ�
        bool sign = false, decimal = false, hasE = false;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'e' || str[i] == 'E') {
                if (i == strlen(str)-1) return false; // e����һ��Ҫ������
                if (hasE) return false;  // ����ͬʱ��������e
                hasE = true;
            } else if (str[i] == '+' || str[i] == '-') {
                // �ڶ��γ���+-���ţ�����������e֮��
                if (sign && str[i-1] != 'e' && str[i-1] != 'E') return false;
                // ��һ�γ���+-���ţ��Ҳ������ַ�����ͷ����Ҳ���������e֮��
                if (!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
                sign = true;
            } else if (str[i] == '.') {
              // e���治�ܽ�С���㣬С���㲻�ܳ�������
                if (hasE || decimal) return false;
                decimal = true;
            } else if (str[i] < '0' || str[i] > '9') // ���Ϸ��ַ�
                return false;
        }
        return true;
    }
};
