#include "Timener.h"
#include "main.h"
#include "imgui/imgui.h"
#include <time.h>
const char* Bosstm(int a, int b)
{

    if (a == 0)
    {
        switch (b)
        {
        case 0:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [0:00] ��������BOSS��ʾ��";
        case 1:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [0:15] ��������BOSS��ʾ��";
        case 2:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [0:30] ��������BOSS��ʾ��";
        case 3:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [0:45] ��������BOSS��ʾ��";
        case 4:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [1:00] ��������BOSS��ʾ��";
        case 5:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [1:15] ��������BOSS��ʾ��";
        case 6:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [1:30] ��������BOSS��ʾ��";
        case 7:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [1:45] ��������BOSS��ʾ��";
        case 8:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [2:00] ��������BOSS��ʾ��";
        case 9:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [2:15] ��������BOSS��ʾ��";
        case 10:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [2:30] ��������BOSS��ʾ��";
        case 11:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [2:45] ��������BOSS��ʾ��";
        case 12:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [3:00] ��������BOSS��ʾ��";
        case 13:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [3:15] ��������BOSS��ʾ��";
        case 14:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [3:30] ��������BOSS��ʾ��";
        case 15:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [3:45] ��������BOSS��ʾ��";
        case 16:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [4:00] ��������BOSS��ʾ��";
        case 17:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [4:15] ��������BOSS��ʾ��";
        case 18:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [4:30] ��������BOSS��ʾ��";
        case 19:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [4:45] ��������BOSS��ʾ��";
        case 20:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [5:00] ��������BOSS��ʾ��";
        case 21:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [5:15] ��������BOSS��ʾ��";
        case 22:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [5:30] ��������BOSS��ʾ��";
        case 23:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [5:45] ��������BOSS��ʾ��";
        case 24:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [6:00] ��������BOSS��ʾ��";
        case 25:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [6:15] ��������BOSS��ʾ��";
        case 26:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [6:30] ��������BOSS��ʾ��";
        case 27:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [6:45] ��������BOSS��ʾ��";
        case 28:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [7:00] ��������BOSS��ʾ��";
        case 29:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [7:15] ��������BOSS��ʾ��";
        case 30:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [7:30] ��������BOSS��ʾ��";
        case 31:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [7:45] ��������BOSS��ʾ��";
        case 32:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [8:00] ��������BOSS��ʾ��";
        case 33:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [8:15] ��������BOSS��ʾ��";
        case 34:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [8:30] ��������BOSS��ʾ��";
        case 35:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [8:45] ��������BOSS��ʾ��";
        case 36:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [9:00] ��������BOSS��ʾ��";
        case 37:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [9:15] ��������BOSS��ʾ��";
        case 38:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [9:30] ��������BOSS��ʾ��";
        case 39:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [9:45] ��������BOSS��ʾ��";
        case 40:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [10:00] ��������BOSS��ʾ��";
        case 41:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [10:15] ��������BOSS��ʾ��";
        case 42:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [10:30] ��������BOSS��ʾ��";
        case 43:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [10:45] ��������BOSS��ʾ��";
        case 44:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [11:00] ��������BOSS��ʾ��";
        case 45:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [11:15] ��������BOSS��ʾ��";
        case 46:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [11:30] ��������BOSS��ʾ��";
        case 47:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [11:45] ��������BOSS��ʾ��";
        case 48:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [12:00] ��������BOSS��ʾ��";
        case 49:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [12:15] ��������BOSS��ʾ��";
        case 50:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [12:30] ��������BOSS��ʾ��";
        case 51:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [12:45] ��������BOSS��ʾ��";
        case 52:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [13:00] ��������BOSS��ʾ��";
        case 53:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [13:15] ��������BOSS��ʾ��";
        case 54:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [13:30] ��������BOSS��ʾ��";
        case 55:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [13:45] ��������BOSS��ʾ��";
        case 56:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [14:00] ��������BOSS��ʾ��";
        case 57:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [14:15] ��������BOSS��ʾ��";
        case 58:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [14:30] ��������BOSS��ʾ��";
        case 59:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [14:45] ��������BOSS��ʾ��";
        case 60:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [15:00] ��������BOSS��ʾ��";
        case 61:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [15:15] ��������BOSS��ʾ��";
        case 62:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [15:30] ��������BOSS��ʾ��";
        case 63:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [15:45] ��������BOSS��ʾ��";
        case 64:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [16:00] ��������BOSS��ʾ��";
        case 65:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [16:15] ��������BOSS��ʾ��";
        case 66:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [16:30] ��������BOSS��ʾ��";
        case 67:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [16:45] ��������BOSS��ʾ��";
        case 68:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [17:00] ��������BOSS��ʾ��";
        case 69:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [17:15] ��������BOSS��ʾ��";
        case 70:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [17:30] ��������BOSS��ʾ��";
        case 71:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [17:45] ��������BOSS��ʾ��";
        case 72:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [18:00] ��������BOSS��ʾ��";
        case 73:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [18:15] ��������BOSS��ʾ��";
        case 74:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [18:30] ��������BOSS��ʾ��";
        case 75:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [18:45] ��������BOSS��ʾ��";
        case 76:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [19:00] ��������BOSS��ʾ��";
        case 77:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [19:15] ��������BOSS��ʾ��";
        case 78:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [19:30] ��������BOSS��ʾ��";
        case 79:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [19:45] ��������BOSS��ʾ��";
        case 80:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [20:00] ��������BOSS��ʾ��";
        case 81:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [20:15] ��������BOSS��ʾ��";
        case 82:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [20:30] ��������BOSS��ʾ��";
        case 83:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [20:45] ��������BOSS��ʾ��";
        case 84:
            return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [21:00] ��������BOSS��ʾ��";
        case 85:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [21:15] ��������BOSS��ʾ��";
        case 86:
            return u8"����BOSS���� <<������ >>[&BLEAAAA=] [21:30] ��������BOSS��ʾ��";
        case 87:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [21:45] ��������BOSS��ʾ��";
        case 88:
            return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [22:00] ��������BOSS��ʾ��";
        case 89:
            return u8"����BOSS���� <<������ >>[&BH4BAAA=] [22:15] ��������BOSS��ʾ��";
        case 90:
            return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [22:30] ��������BOSS��ʾ��";
        case 91:
            return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [22:45] ��������BOSS��ʾ��";
        case 92:
            return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [23:00] ��������BOSS��ʾ��";
        case 93:
            return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [23:15] ��������BOSS��ʾ��";
        case 94:
            return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [23:30] ��������BOSS��ʾ��";
        case 95:
            return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [23:45] ��������BOSS��ʾ��";
        default:
            return u8"δ֪����";
        }
    }
    if (a == 1)
    {
        switch (b)
        {
        case 0:
            return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [0:00] ��������BOSS��ʾ��";
        case 1:
            return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [0:20] ��������BOSS��ʾ��";
        case 2:
            return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [0:30] ��������BOSS��ʾ��";
        case 3:
            return u8"";
        case 4:
            return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [1:00] ��������BOSS��ʾ��";
        case 5:
            return u8"";
        case 6:
            return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [1:30] ��������BOSS��ʾ��";
        case 7:
            return u8"�����¼����� ������ [&BPcKAAA=] [1:45] ��������BOSS��ʾ��";
        case 8:
            return u8"";
        case 9:
            return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [2:20] ��������BOSS��ʾ��";
        case 10:
            return u8"��ǰ�¼� Ů���� �������� �������� [2:30] ��������BOSS��ʾ��";
        case 11:
            return u8"";
        case 12:
            return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [3:00] ��������BOSS��ʾ��";
        case 13:
            return u8"";
        case 14:
            return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [3:30] ��������BOSS��ʾ��";
        case 15:
            return u8"�����¼����� ������ [&BPcKAAA=] [3:45] ��������BOSS��ʾ��";
        case 16:
            return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [4:00] ��������BOSS��ʾ��";
        case 17:
            return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [4:20] ��������BOSS��ʾ��";
        case 18:
            return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� [4:30] ��������BOSS��ʾ��";
        case 19:
            return u8"";
        case 20:
            return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [5:00] ��������BOSS��ʾ��";
        case 21:
            return u8"";
        case 22:
            return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [5:30] ��������BOSS��ʾ��";
        case 23:
            return u8"�����¼����� ������ [&BPcKAAA=] [5:45] ��������BOSS��ʾ��";
        case 24:
            return u8"";
        case 25:
            return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [6:20] ��������BOSS��ʾ��";
        case 26:
            return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [6:30] ��������BOSS��ʾ��";
        case 27:
            return u8"";
        case 28:
            return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [7:00] ��������BOSS��ʾ��";
        case 29:
            return u8"";
        case 30:
            return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [7:30] ��������BOSS��ʾ��";
        case 31:
            return u8"�����¼����� ������ [&BPcKAAA=] [7:45] ��������BOSS��ʾ��";
        case 32:
            return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [8:00] ��������BOSS��ʾ��";
        case 33:
            return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [8:20] ��������BOSS��ʾ��";
        case 34:
            return u8"��ǰ�¼� Ů���� �������� �������� [8:30] ��������BOSS��ʾ��";
        case 35:
            return u8"";
        case 36:
            return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [9:00] ��������BOSS��ʾ��";
        case 37:
            return u8"";
        case 38:
            return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [9:30] ��������BOSS��ʾ��";
        case 39:
            return u8"�����¼����� ������ [&BPcKAAA=] [9:45] ��������BOSS��ʾ��";
        case 40:
            return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [10:00] ��������BOSS��ʾ��";
        case 41:
            return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [10:20] ��������BOSS��ʾ��";
        case 42:
            return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� [10:30] ��������BOSS��ʾ��";
        case 43:
            return u8"";
        case 44:
            return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [11:00] ��������BOSS��ʾ��";
        case 45:
            return u8"";
        case 46:
            return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [11:30] ��������BOSS��ʾ��";
        case 47:
            return u8"�����¼����� ������ [&BPcKAAA=] [11:45] ��������BOSS��ʾ��";
        case 48:
            return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [12:00] ��������BOSS��ʾ��";
        case 49:
            return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [12:20] ��������BOSS��ʾ��";
        case 50:
            return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [12:30] ��������BOSS��ʾ��";
        case 51:
            return u8"";
        case 52:
            return u8"";
        case 53:
            return u8"";
        case 54:
            return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [13:30] ��������BOSS��ʾ��";
        case 55:
            return u8"�����¼����� ������ [&BPcKAAA=] [13:45] ��������BOSS��ʾ��";
        case 56:
            return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [14:00] ��������BOSS��ʾ��";
        case 57:
            return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [14:20] ��������BOSS��ʾ��";
        case 58:
            return u8"��ǰ�¼� Ů���� �������� �������� [14:30] ��������BOSS��ʾ��";
        case 59:
            return u8"";
        case 60:
            return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [15:00] ��������BOSS��ʾ��";
        case 61:
            return u8"";
        case 62:
            return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [15:30] ��������BOSS��ʾ��";
        case 63:
            return u8"�����¼����� ������ [&BPcKAAA=] [15:45] ��������BOSS��ʾ��";
        case 64:
            return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [16:00] ��������BOSS��ʾ��";
        case 65:
            return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [16:20] ��������BOSS��ʾ��";
        case 66:
            return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� 16:30] ��������BOSS��ʾ��";
        case 67:
            return u8"";
        case 68:
            return u8"";
        case 69:
            return u8"";
        case 70:
            return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [17:30] ��������BOSS��ʾ��";
        case 71:
            return u8"�����¼����� ������ [&BPcKAAA=] [17:45] ��������BOSS��ʾ��";
        case 72:
            return u8"";
        case 73:
            return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [18:20] ��������BOSS��ʾ��";
        case 74:
            return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [18:30] ��������BOSS��ʾ��";
        case 75:
            return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [18:30] ��������BOSS��ʾ��";
        case 76:
            return u8"";
        case 77:
            return u8"";
        case 78:
            return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [19:30] ��������BOSS��ʾ��";
        case 79:
            return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [19:30] ��������BOSS��ʾ��";
        case 80:
            return u8"�����¼����� ������ [&BPcKAAA=] [19:45] ��������BOSS��ʾ��";
        case 81:
            return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [20:20] ��������BOSS��ʾ��";
        case 82:
            return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [20:30]  ��������BOSS��ʾ��";
        case 83:
            return u8"��ǰ�¼� Ů���� �������� �������� [20:30] ��������BOSS��ʾ��";
        case 84:
            return u8"";
        case 85:
            return u8"";
        case 86:
            return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [21:30] ��������BOSS��ʾ��";
        case 87:
            return u8"�����¼����� ������ [&BPcKAAA=] [21:45] ��������BOSS��ʾ��";
        case 88:
            return u8"";
        case 89:
            return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [22:20] ��������BOSS��ʾ��";
        case 90:
            return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� [22:30] ��������BOSS��ʾ��";
        case 91:
            return u8"";
        case 92:
            return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [23:00] ��������BOSS��ʾ��";
        case 93:
            return u8"";
        case 94:
            return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [23:30] ��������BOSS��ʾ��";
        case 95:
            return u8"�����¼����� ������ [&BPcKAAA=] [23:45] ��������BOSS��ʾ��";
        default:
            return u8"δ֪����";
        }
    }
    if (a == 2)
    {
        switch (b)
        {
        case 0:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [0:05] ��������BOSS��ʾ��";
        case 1:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [0:10] ��������BOSS��ʾ��";
        case 2:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [0:30] ��������BOSS��ʾ��";
        case 3:
            return u8"";
        case 4:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [1:00] ��������BOSS��ʾ��";
        case 5:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [1:00] ��������BOSS��ʾ��";
        case 6:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [1:30] ��������BOSS��ʾ��";
        case 7:
            return u8"";
        case 8:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [2:05] ��������BOSS��ʾ��";
        case 9:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [2:10] ��������BOSS��ʾ��";
        case 10:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [2:30] ��������BOSS��ʾ��";
        case 11:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [2:30] ��������BOSS��ʾ��";
        case 12:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [3:00] ��������BOSS��ʾ��";
        case 13:
            return u8"";
        case 14:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [3:30] ��������BOSS��ʾ��";
        case 15:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [4:00] ��������BOSS��ʾ��";
        case 16:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [4:05] ��������BOSS��ʾ��";
        case 17:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [4:10] ��������BOSS��ʾ��";
        case 18:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [4:30] ��������BOSS��ʾ��";
        case 19:
            return u8"";
        case 20:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [5:00] ��������BOSS��ʾ��";
        case 21:
            return u8"";
        case 22:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [5:30] ��������BOSS��ʾ��";
        case 23:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [5:30] ��������BOSS��ʾ��";
        case 24:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [6:05] ��������BOSS��ʾ��";
        case 25:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [6:10] ��������BOSS��ʾ��";
        case 26:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [6:30] ��������BOSS��ʾ��";
        case 27:
            return u8"";
        case 28:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [7:00] ��������BOSS��ʾ��";
        case 29:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [7:00] ��������BOSS��ʾ��";
        case 30:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [7:30] ��������BOSS��ʾ��";
        case 31:
            return u8"";
        case 32:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [8:05] ��������BOSS��ʾ��";
        case 33:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [8:10] ��������BOSS��ʾ��";
        case 34:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [8:30] ��������BOSS��ʾ��";
        case 35:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [8:30] ��������BOSS��ʾ��";
        case 36:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [9:00] ��������BOSS��ʾ��";
        case 37:
            return u8"";
        case 38:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [9:30] ��������BOSS��ʾ��";
        case 39:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [10:00] ��������BOSS��ʾ��";
        case 40:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [10:05] ��������BOSS��ʾ��";
        case 41:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [10:10] ��������BOSS��ʾ��";
        case 42:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [10:30] ��������BOSS��ʾ��";
        case 43:
            return u8"";
        case 44:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [11:00] ��������BOSS��ʾ��";
        case 45:
            return u8"";
        case 46:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [11:30] ��������BOSS��ʾ��";
        case 47:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [11:30] ��������BOSS��ʾ��";
        case 48:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [12:05] ��������BOSS��ʾ��";
        case 49:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [12:10] ��������BOSS��ʾ��";
        case 50:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [12:30] ��������BOSS��ʾ��";
        case 51:
            return u8"";
        case 52:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [13:00] ��������BOSS��ʾ��";
        case 53:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [13:00] ��������BOSS��ʾ��";
        case 54:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [13:30] ��������BOSS��ʾ��";
        case 55:
            return u8"";
        case 56:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [14:05] ��������BOSS��ʾ��";
        case 57:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [14:10] ��������BOSS��ʾ��";
        case 58:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [14:30] ��������BOSS��ʾ��";
        case 59:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [14:30] ��������BOSS��ʾ��";
        case 60:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [15:00] ��������BOSS��ʾ��";
        case 61:
            return u8"";
        case 62:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [15:30] ��������BOSS��ʾ��";
        case 63:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [16:00] ��������BOSS��ʾ��";
        case 64:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [16:05] ��������BOSS��ʾ��";
        case 65:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [16:10] ��������BOSS��ʾ��";
        case 66:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [16:30] ��������BOSS��ʾ��";
        case 67:
            return u8"";
        case 68:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [17:00] ��������BOSS��ʾ��";
        case 69:
            return u8"";
        case 70:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [17:30] ��������BOSS��ʾ��";
        case 71:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [17:30] ��������BOSS��ʾ��";
        case 72:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [18:05] ��������BOSS��ʾ��";
        case 73:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [18:10] ��������BOSS��ʾ��";
        case 74:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [18:30] ��������BOSS��ʾ��";
        case 75:
            return u8"";
        case 76:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [19:00] ��������BOSS��ʾ��";
        case 77:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [19:00] ��������BOSS��ʾ��";
        case 78:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [19:30] ��������BOSS��ʾ��";
        case 79:
            return u8"";
        case 80:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [20:05] ��������BOSS��ʾ��";
        case 81:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [20:10] ��������BOSS��ʾ��";
        case 82:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [20:30] ��������BOSS��ʾ��";
        case 83:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [20:30] ��������BOSS��ʾ��";
        case 84:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [21:00] ��������BOSS��ʾ��";
        case 85:
            return u8"";
        case 86:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [21:30] ��������BOSS��ʾ��";
        case 87:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [22:00] ��������BOSS��ʾ��";
        case 88:
            return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [22:05] ��������BOSS��ʾ��";
        case 89:
            return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [22:10] ��������BOSS��ʾ��";
        case 90:
            return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [22:30] ��������BOSS��ʾ��";
        case 91:
            return u8"";
        case 92:
            return u8"�����¼����� <<�������>>  [&BGwIAAA=] [23:00] ��������BOSS��ʾ��";
        case 93:
            return u8"";
        case 94:
            return u8"�����¼����� <<�������>> [&BBAIAAA=] [23:30] ��������BOSS��ʾ��";
        case 95:
            return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [23:30] ��������BOSS��ʾ��";
        default:
            return u8"δ֪����";
        }

    }
    return u8"δ֪����";
}
enum class bossname
{
    ���Ѿ���,
    ������,
    ������,
    ��Ԫ��,
    ħ��,
    �ֵس�,
    ׿��,
    ��Ӱ����,
    ���Ķ�,
    ���ܻ���,//9
    ��ʬ��,
    ����1,
    ��ǰ�¼�1,
    �����鷳,
    ��ǰ�¼�2,
    ������,
    ����2,
    ��ǰ�¼�3,
    ���ǳ�Ů��,
    ��ǰ�¼�4,
    ����3,
    ��ǰ�¼�5,
    ��ǰ�¼�6,
    ��,//23
    �ĳ�����ս,
    ��ĸ,
    ����,
    ����,
    ����,
    ����,

};
const char* GetBossName(bossname m)
{
    switch (m)
    {
    case bossname::���Ѿ���:
        return u8"���Ѿ���";
    case bossname::������:
        return u8"������";
    case bossname::������:
        return u8"������";
    case bossname::��Ԫ��:
        return u8"��Ԫ��";
    case bossname::ħ��:
        return u8"���ħ��";
    case bossname::�ֵس�:
        return u8"�ֵس�";
    case bossname::׿��:
        return u8"����׿��";
    case bossname::��Ӱ����:
        return u8"��Ӱ����";
    case bossname::���Ķ�:
        return u8"���Ķٺ���";
    case bossname::���ܻ���:
        return u8"���ܻ���";
    case bossname::��ʬ��:
        return u8"��ʬ��";
    case bossname::����1:
        return u8"�ʴ���ս������";
    case bossname::��ǰ�¼�1:
        return u8"��ǰ�¼�1";
    case bossname::�����鷳:
        return u8"�����鷳";
    case bossname::��ǰ�¼�2:
        return u8"��ǰ�¼�2";
    case bossname::������:
        return u8"��˹̹������";
    case bossname::����2:
        return u8"�����ٲ�����";
    case bossname::��ǰ�¼�3:
        return u8"��ǰ�¼�3";
    case bossname::���ǳ�Ů��:
        return u8"���ǳ�Ů��";
    case bossname::��ǰ�¼�4:
        return u8"��ǰ�¼�4";
    case bossname::����3:
        return u8"����ƽԭ����";
    case bossname::��ǰ�¼�5:
        return u8"��ǰ�¼�5";
    case bossname::��ǰ�¼�6:
        return u8"��ǰ�¼�6";
    case bossname::�ĳ�����ս:
        return u8"�ĳ�����ս";
    case bossname::��ĸ:
        return u8"�Դ���ĸ";
    case bossname::����:
        return u8"���ٳ���";
    case bossname::����:
        return u8"�������";
    case bossname::����:
        return u8"�߱Ⱦ���";
    case bossname::����:
        return u8"�������";
    case bossname::��:
        return u8"";
    default:
        return u8"[δ֪]";
    }
};

bool Timeners(const std::string& name, bool & setting)
{
    if (setting)
    {
        int ass[96] = {};
        int bosstimepaixu0[96] = { 0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9,7,0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9,7,0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9,7,0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9, 7, };
        int bosstimepaixu1[96] = { 10, 11, 12, 23, 13, 23, 14, 15, 23, 16, 17, 23, 18, 23, 19, 15, 10, 20, 21, 23, 13, 23, 22, 15, 23, 11, 12, 23, 18, 23, 14, 15, 10, 16, 17, 23, 13, 23, 19, 15, 18, 20, 21, 23, 10, 23, 22, 15, 13, 11, 12, 23, 23, 23, 14, 15, 18, 16, 17, 23, 10, 23, 19, 15, 13, 20, 21, 23, 23, 23, 22, 15, 10, 11, 18, 12, 23, 23, 10, 14, 15, 16, 13, 17, 23, 23, 19, 15, 23, 20, 21, 23, 18, 23, 22, 15, };
        int bosstimepaixu2[96] = { 24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28,24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28,24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28,24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28, };
        ImGui::SetNextWindowBgAlpha(0.4f);
        //ImGui::Begin(u8"BOSS��ʱ��_byӡ������", &setting, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Begin(name.c_str(), &setting, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
        static int lines = 3;
        ImGui::GetStyle().WindowBorderSize = 0.0f;
        ImGui::GetStyle().ChildBorderSize = 0.0f;
        ImGui::GetStyle().WindowPadding = ImVec2(5, 5);
        ImGui::GetStyle().ItemSpacing = ImVec2(1, 1);
        ImGui::BeginChild("scrolling", ImVec2(247, 65), false);
        for (int line = 0; line < lines; line++)
        {
            int num_buttons = 96;
            int h = 0;
            int s = 0;
            if (line == 0) memcpy(ass, bosstimepaixu0, sizeof(bosstimepaixu0));
            if (line == 1) memcpy(ass, bosstimepaixu1, sizeof(bosstimepaixu1));
            if (line == 2) memcpy(ass, bosstimepaixu2, sizeof(bosstimepaixu2));
            for (int n = 0; n < num_buttons; n++)
            {
                if (n != 0) ImGui::SameLine(0.0f, 0.0f);
                ImGui::PushID(n + line * 1000);
                const char* label = GetBossName(bossname(ass[n]));
                float hue = n * 0.02083f;
                ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(hue, 0.6f, 0.6f, 0.44f));
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(hue, 0.7f, 0.7f, 0.44f));
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(hue, 0.8f, 0.8f, 0.44f));

                if (line == 0)
                {
                    char num_buf[32];
                    char str3[32];
                    sprintf_s(num_buf, u8"[%d:%d]", h, s);
                    strcpy_s(str3, num_buf);
                    strcat_s(str3, label);
                    label = str3;
                    if (s < 60)s = s + 15;
                    if (s == 60)h++, s = 0;
                }
                if (ImGui::Button(label, ImVec2(82.0f, 19)))
                {
                    ImGui::SetClipboardText(Bosstm(line, n));
                }
                ImGui::PopStyleColor(3);
                ImGui::PopID();
            }
        }
        
        ImGui::EndChild();
        time_t time_seconds = time(0);
        tm now_time;
        localtime_s(&now_time, &time_seconds);
        float scroll_x_delta = 0.0f;
        if (ImGui::GetIO().WantCaptureMouse == 1)
        {
            if (ImGui::SmallButton("<<------------------"))scroll_x_delta = -82; ImGui::SameLine();
            if (ImGui::SmallButton(u8"�� ��")) setting = false; ImGui::SameLine();
            if (ImGui::SmallButton("------------------>>"))scroll_x_delta = +82; ImGui::SameLine();
            if (scroll_x_delta != 0.0f)ImGui::BeginChild("scrolling"), ImGui::SetScrollX(ImGui::GetScrollX() + scroll_x_delta), ImGui::EndChild();
        }
        else
        {
            ImGui::BeginChild("scrolling");
            if (now_time.tm_hour * 60 + now_time.tm_min < 30)
            {
                ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15) * 82.0f);
            }
            else
            {
                ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15 - 1) * 82.0f);
            }
            ImGui::EndChild();
            
        }
        ImGui::End();
    }
    return setting;
}
