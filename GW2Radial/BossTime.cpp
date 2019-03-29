#include "BossTime.h"
//#include <SettingsMenu.h>
#include <MiscTab.h>
#include <imgui.h>
#include <time.h>
#include <WinInet.h>
#include <sstream>
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

namespace GW2Radial
{

	
	
	DEFINE_SINGLETON(BossTime);
#pragma region ��ʱ������
	const char* Bosstm(int a, int b)
	{

		if (a == 0)
		{
			switch (b)
			{
			case 0:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [0:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 1:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [0:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 2:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [0:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 3:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [0:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 4:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [1:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 5:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [1:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 6:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [1:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 7:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [1:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 8:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [2:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 9:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [2:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 10:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [2:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 11:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [2:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 12:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [3:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 13:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [3:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 14:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [3:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 15:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [3:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 16:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [4:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 17:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [4:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 18:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [4:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 19:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [4:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 20:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [5:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 21:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [5:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 22:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [5:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 23:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [5:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 24:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [6:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 25:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [6:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 26:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [6:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 27:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [6:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 28:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [7:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 29:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [7:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 30:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [7:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 31:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [7:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 32:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [8:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 33:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [8:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 34:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [8:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 35:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [8:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 36:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [9:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 37:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [9:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 38:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [9:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 39:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [9:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 40:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [10:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 41:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [10:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 42:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [10:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 43:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [10:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 44:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [11:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 45:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [11:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 46:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [11:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 47:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [11:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 48:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [12:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 49:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [12:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 50:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [12:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 51:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [12:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 52:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [13:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 53:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [13:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 54:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [13:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 55:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [13:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 56:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [14:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 57:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [14:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 58:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [14:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 59:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [14:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 60:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [15:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 61:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [15:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 62:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [15:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 63:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [15:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 64:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [16:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 65:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [16:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 66:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [16:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 67:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [16:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 68:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [17:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 69:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [17:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 70:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [17:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 71:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [17:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 72:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [18:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 73:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [18:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 74:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [18:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 75:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [18:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 76:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [19:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 77:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [19:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 78:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [19:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 79:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [19:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 80:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [20:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 81:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [20:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 82:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [20:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 83:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [20:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 84:
				return u8"����BOSS���� <<���Ѿ��� >>[&BE4DAAA=] [21:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 85:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [21:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 86:
				return u8"����BOSS���� <<������ >>[&BLEAAAA=] [21:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 87:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [21:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 88:
				return u8"����BOSS���� <<ħ�� >>[&BNQCAAA=] [22:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 89:
				return u8"����BOSS���� <<������ >>[&BH4BAAA=] [22:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 90:
				return u8"����BOSS���� <<׿�� >>[&BHoCAAA=] [22:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 91:
				return u8"����BOSS���� <<��Ԫ�� >>[&BEYAAAA=] [22:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 92:
				return u8"����BOSS���� <<���Ķ� >>[&BKgBAAA=] [23:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 93:
				return u8"����BOSS���� <<�ֵس� >>[&BEEFAAA=] [23:15] ����\"gw2sy.top\"����boss��ʾ��";
			case 94:
				return u8"����BOSS���� <<���ܻ��� >>[&BM0CAAA=] [23:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 95:
				return u8"����BOSS���� <<��Ӱ���� >>[&BPwAAAA=] [23:45] ����\"gw2sy.top\"����boss��ʾ��";
			default:
				return u8"δ֪����";
			}
		}
		if (a == 1)
		{
			switch (b)
			{
			case 0:
				return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [0:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 1:
				return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [0:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 2:
				return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [0:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 3:
				return u8"";
			case 4:
				return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [1:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 5:
				return u8"";
			case 6:
				return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [1:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 7:
				return u8"�����¼����� ������ [&BPcKAAA=] [1:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 8:
				return u8"";
			case 9:
				return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [2:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 10:
				return u8"��ǰ�¼� Ů���� �������� �������� [2:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 11:
				return u8"";
			case 12:
				return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [3:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 13:
				return u8"";
			case 14:
				return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [3:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 15:
				return u8"�����¼����� ������ [&BPcKAAA=] [3:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 16:
				return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [4:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 17:
				return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [4:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 18:
				return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� [4:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 19:
				return u8"";
			case 20:
				return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [5:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 21:
				return u8"";
			case 22:
				return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [5:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 23:
				return u8"�����¼����� ������ [&BPcKAAA=] [5:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 24:
				return u8"";
			case 25:
				return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [6:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 26:
				return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [6:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 27:
				return u8"";
			case 28:
				return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [7:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 29:
				return u8"";
			case 30:
				return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [7:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 31:
				return u8"�����¼����� ������ [&BPcKAAA=] [7:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 32:
				return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [8:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 33:
				return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [8:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 34:
				return u8"��ǰ�¼� Ů���� �������� �������� [8:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 35:
				return u8"";
			case 36:
				return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [9:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 37:
				return u8"";
			case 38:
				return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [9:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 39:
				return u8"�����¼����� ������ [&BPcKAAA=] [9:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 40:
				return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [10:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 41:
				return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [10:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 42:
				return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� [10:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 43:
				return u8"";
			case 44:
				return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [11:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 45:
				return u8"";
			case 46:
				return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [11:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 47:
				return u8"�����¼����� ������ [&BPcKAAA=] [11:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 48:
				return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [12:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 49:
				return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [12:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 50:
				return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [12:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 51:
				return u8"";
			case 52:
				return u8"";
			case 53:
				return u8"";
			case 54:
				return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [13:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 55:
				return u8"�����¼����� ������ [&BPcKAAA=] [13:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 56:
				return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [14:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 57:
				return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [14:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 58:
				return u8"��ǰ�¼� Ů���� �������� �������� [14:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 59:
				return u8"";
			case 60:
				return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [15:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 61:
				return u8"";
			case 62:
				return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [15:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 63:
				return u8"�����¼����� ������ [&BPcKAAA=] [15:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 64:
				return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [16:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 65:
				return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [16:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 66:
				return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� 16:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 67:
				return u8"";
			case 68:
				return u8"";
			case 69:
				return u8"";
			case 70:
				return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [17:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 71:
				return u8"�����¼����� ������ [&BPcKAAA=] [17:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 72:
				return u8"";
			case 73:
				return u8"��ǰ�¼� �ʴ���ս�� ���� [&BJEBAAA=] [18:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 74:
				return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [18:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 75:
				return u8"��ǰ�¼� ��˹����ƽԭ �������� ������֮ɭ [18:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 76:
				return u8"";
			case 77:
				return u8"";
			case 78:
				return u8"����BOSS���� <<��ʬ��>> [&BNABAAA=] [19:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 79:
				return u8"��ǰ�¼� Ů���� �ʴ���ս�� ������֮ɭ [19:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 80:
				return u8"�����¼����� ������ [&BPcKAAA=] [19:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 81:
				return u8"��ǰ�¼� �����ٲ� ���� [&BEYEAAA=] [20:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 82:
				return u8"����BOSS���� <<�����鷳>> [&BKoBAAA=] [20:30]  ����\"gw2sy.top\"����boss��ʾ��";
			case 83:
				return u8"��ǰ�¼� Ů���� �������� �������� [20:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 84:
				return u8"";
			case 85:
				return u8"";
			case 86:
				return u8"��ǰ�¼� �������� ��˹����ƽԭ ������֮ɭ [21:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 87:
				return u8"�����¼����� ������ [&BPcKAAA=] [21:45] ����\"gw2sy.top\"����boss��ʾ��";
			case 88:
				return u8"";
			case 89:
				return u8"��ǰ�¼� ����ƽԭ ���� [&BOkBAAA=] [22:20] ����\"gw2sy.top\"����boss��ʾ��";
			case 90:
				return u8"��ǰ�¼� Ů���� ��˹����ƽԭ �ʴ���ս�� [22:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 91:
				return u8"";
			case 92:
				return u8"����BOSS���� <<���ǳ�Ů��>> [&BNcGAAA=] [23:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 93:
				return u8"";
			case 94:
				return u8"��ǰ�¼� �������� �ʴ���ս�� �������� [23:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 95:
				return u8"�����¼����� ������ [&BPcKAAA=] [23:45] ����\"gw2sy.top\"����boss��ʾ��";
			default:
				return u8"δ֪����";
			}
		}
		if (a == 2)
		{
			switch (b)
			{
			case 0:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [0:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 1:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [0:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 2:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [0:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 3:
				return u8"";
			case 4:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [1:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 5:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [1:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 6:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [1:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 7:
				return u8"";
			case 8:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [2:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 9:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [2:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 10:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [2:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 11:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [2:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 12:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [3:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 13:
				return u8"";
			case 14:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [3:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 15:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [4:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 16:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [4:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 17:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [4:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 18:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [4:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 19:
				return u8"";
			case 20:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [5:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 21:
				return u8"";
			case 22:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [5:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 23:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [5:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 24:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [6:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 25:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [6:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 26:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [6:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 27:
				return u8"";
			case 28:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [7:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 29:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [7:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 30:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [7:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 31:
				return u8"";
			case 32:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [8:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 33:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [8:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 34:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [8:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 35:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [8:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 36:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [9:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 37:
				return u8"";
			case 38:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [9:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 39:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [10:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 40:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [10:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 41:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [10:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 42:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [10:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 43:
				return u8"";
			case 44:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [11:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 45:
				return u8"";
			case 46:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [11:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 47:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [11:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 48:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [12:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 49:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [12:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 50:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [12:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 51:
				return u8"";
			case 52:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [13:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 53:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [13:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 54:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [13:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 55:
				return u8"";
			case 56:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [14:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 57:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [14:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 58:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [14:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 59:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [14:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 60:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [15:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 61:
				return u8"";
			case 62:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [15:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 63:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [16:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 64:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [16:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 65:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [16:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 66:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [16:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 67:
				return u8"";
			case 68:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [17:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 69:
				return u8"";
			case 70:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [17:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 71:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [17:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 72:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [18:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 73:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [18:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 74:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [18:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 75:
				return u8"";
			case 76:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [19:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 77:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [19:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 78:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [19:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 79:
				return u8"";
			case 80:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [20:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 81:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [20:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 82:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [20:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 83:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [20:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 84:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [21:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 85:
				return u8"";
			case 86:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [21:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 87:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [22:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 88:
				return u8"�����¼����� <<�ĳ�����ս>> [&BLsKAAA=] [22:05] ����\"gw2sy.top\"����boss��ʾ��";
			case 89:
				return u8"�����¼����� <<�Դ���ĸ>> [&BAgIAAA=]  [22:10] ����\"gw2sy.top\"����boss��ʾ��";
			case 90:
				return u8"�����¼����� <<���ٳ���>>  [&BPUHAAA=] [22:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 91:
				return u8"";
			case 92:
				return u8"�����¼����� <<�������>>  [&BGwIAAA=] [23:00] ����\"gw2sy.top\"����boss��ʾ��";
			case 93:
				return u8"";
			case 94:
				return u8"�����¼����� <<�������>> [&BBAIAAA=] [23:30] ����\"gw2sy.top\"����boss��ʾ��";
			case 95:
				return u8"�����¼����� <<����֮ŭ>> [&BHQKAAA=] [23:30] ����\"gw2sy.top\"����boss��ʾ��";
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
#pragma endregion
	BossTime::BossTime():showKeybindweb_("show_BossTime", "Show BossTime", { VK_F8 }, false)
	{
		inputChangeCallbackweb_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChangeweb(changed, keys, changedKeys); };
		Input::i()->AddInputChangeCallback(&inputChangeCallbackweb_);
	}
	BossTime::~BossTime()
	{
		if (auto i = Input::iNoInit(); i)
		{
			i->RemoveInputChangeCallback(&inputChangeCallbackweb_);
		}
	}
	void BossTime::Draw()
	{
		if (!isVisibleweb_ && jishiqi)
		{
			if (MiscTab::i()->showboostime() && kput == 0)
			{
				isVisibleweb_ = true;
				jishiqi = false;
			}
		}
		if (isVisibleweb_)
		{
			kput = 1;
			if (!_DoUI(isVisibleweb_))
			{
				isVisibleweb_ = false;
				jishiqi = true;
			}
		}
	}
#pragma region ��־
	struct ExampleAppLog
	{
		ImGuiTextBuffer     Buf;
		ImGuiTextFilter     Filter;
		ImVector<int>       LineOffsets;        // Index to lines offset
		bool                ScrollToBottom;

		void    Clear() { Buf.clear(); LineOffsets.clear(); }

		void    AddLog(const char* fmt, ...) IM_FMTARGS(2)
		{
			int old_size = Buf.size();
			va_list args;
			va_start(args, fmt);
			Buf.appendfv(fmt, args);
			Buf.appendfv("\r\n", args);
			va_end(args);
			for (int new_size = Buf.size(); old_size < new_size; old_size++)
				if (Buf[old_size] == '\n')
					LineOffsets.push_back(old_size);
			ScrollToBottom = true;
		}

		void    Draw(const char* title, bool* p_open = NULL)
		{
			ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
			if (!ImGui::Begin(title, p_open))
			{
				ImGui::End();
				return;
			}
			if (ImGui::Button(u8"ȡ��")) Clear();
			ImGui::SameLine();
			bool copy = ImGui::Button(u8"����");
			ImGui::SameLine();
			Filter.Draw(u8"������", -100.0f);
			ImGui::Separator();
			ImGui::BeginChild(u8"����", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
			if (copy) ImGui::LogToClipboard();

			if (Filter.IsActive())
			{
				const char* buf_begin = Buf.begin();
				const char* line = buf_begin;
				for (int line_no = 0; line != NULL; line_no++)
				{
					const char* line_end = (line_no < LineOffsets.Size) ? buf_begin + LineOffsets[line_no] : NULL;
					if (Filter.PassFilter(line, line_end))
						ImGui::TextUnformatted(line, line_end);
					line = line_end && line_end[1] ? line_end + 1 : NULL;
				}
			}
			else
			{
				ImGui::TextUnformatted(Buf.begin());
			}

			//if (ScrollToBottom)
				//ImGui::SetScrollHereY(1.0f);
			ScrollToBottom = false;
			ImGui::EndChild();
			ImGui::End();
		}
	};
	static ExampleAppLog log;//
	bool is = true;//
#pragma endregion

#pragma region ��ҳ��ȡ
	bool geting = true;
	//bool geting_t = true;//����id��ȡ��
	//bool geting_t_n = true;//�������ֻ�ȡ��
	//int shu = 0;
	//int zhengshu = 0;//��ʵ����
	bool wancheng = false;
	//bool wancheng_t = false;//����id��ȡ���
	//bool wancheng_t_n = false;//�������ֻ�ȡ���
	const char* W_arrc = nullptr;//���а�
	const char * W_time1 = nullptr;//ʱ��
	const char * W_time2 = nullptr;//ʱ��
	std::string* FetchReleaseData(const char * days);//������ȡ��������
	//void getTomorrowids();//������ȡ�����ճ�ID����
	//void getTomorrownames(std::string date);//������ȡ�����ճ����ַ���
	//std::string Gettmpstring(std::string line, std::string beginFlag, std::string endFlag); //������ȡ�����ճ�ID�ֶεķ���
	//std::string * Getiads(std::string line, std::string beginFlag, std::string endFlag, std::string end);//������ȡ�����ճ�ID�ķ���
	std::string * W_renwu1 = new std::string[5];//������ʾ
	std::string * W_renwu2 = new std::string[5];//���ﱣ����ʾ
	std::string* result = new std::string[6];//���ﴢ��
	std::string* tmpIDname = new std::string[32];//���ﴢ��
	//std::string Tomorrowids;//����ID��jons
	//std::string Tomorrowids_;//����ID����
	////���ִ������=========================
	//std::string beginFlag = u8"id";
	//std::string endFlag = u8",";
	//std::string end = u8"special";
	////std::string line2 ;
	//std::string pvebeginFlag = u8"pve";
	//std::string pvpbeginFlag = u8"pvp";
	//std::string wvwbeginFlag = u8"wvw";
	//std::string ftsbeginFlag = u8"fractals";
	//std::string end2Flag = u8"special";
	////====
	//std::string * PVEname = new std::string[15];//
	//std::string * PVPname = new std::string[4];//
	//std::string * WVWname = new std::string[4];//
	//std::string * FTSname = new std::string[6];//
	//int A_ = 0;//pve����


	LPCWSTR stringToLPCWSTR(std::string orig);//����ת��
	LPCWSTR stringToLPCWSTR(std::string orig)
	{
		//std::string tmpss1 = orig;
		size_t origsize = orig.length() + 1;
		const size_t newsize = 100;
		size_t convertedChars = 0;
		wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
		mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
		return wcstring;
	}
	const char *  GetTime(int day)
	{
		using namespace boost::gregorian;
		boost::gregorian::date nowday = day_clock::local_day();
		boost::gregorian::date d2 = nowday + boost::gregorian::days(day);
		boost::gregorian::day_iterator d_iter(d2);
		std::string strTime = boost::gregorian::to_iso_extended_string(*d_iter);
		char* out = new char[strTime.length()];
		for (int i = 0; i <= strTime.length(); ++i)
			out[i] = strTime[i];
		return out;
	}

	std::string* FetchReleaseData(const char * days)
	{
		wancheng = false;
		std::string retVal;
		const auto handle = InternetOpen(L"getwebname", INTERNET_OPEN_TYPE_PRECONFIG, nullptr, nullptr, 0);
		if (handle == nullptr)
		{
			InternetCloseHandle(handle);
			result[0] = "0";
			geting = false;
			wancheng = true;
		}
		std::string _a = "http://do.gw2.kongzhong.com/task/completes?date=";
		std::string _b = days;
		std::string _tmp = _a + _b;
		LPCWSTR ul = stringToLPCWSTR(_tmp);

		const auto request = InternetOpenUrl(handle, ul, nullptr, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
		delete(ul);

		if (request == nullptr)
		{
			InternetCloseHandle(request);
			result[0] = "0";
			geting = false;
			wancheng = true;
		}
		char response_data[8000];//������
		DWORD response_length = 0;

		if (InternetReadFile(request, response_data, sizeof(response_data) - 1, &response_length) && response_length > 0)
		{
			response_data[response_length] = '\0';
			response_length++;
		}
		InternetCloseHandle(request);
		InternetCloseHandle(handle);
		retVal = response_data;

		if (response_length > 200)
		{
			std::string beginFlag = u8"task_name";
			std::string endFlag = u8",";
			std::string end = u8"}";
			int startPos = 0;
			int endPos = 0;
			int beginPos = 0;
			int endingpos = 0;
			for (int i = 0; i < 6; i++)
			{
				startPos = (int)retVal.find(beginFlag, startPos);
				endPos = (int)retVal.find(endFlag, startPos);
				beginPos = startPos + (int)beginFlag.length() + 2;
				endingpos = endPos - startPos - (int)beginFlag.length() - 2;
				result[i] = retVal.substr(beginPos, endingpos);
				if ((int)result[i].find(end) > 0)
				{
					result[i].replace(result[i].size() - 1, result[i].size(), "");
					if ((int)result[i].find(end) > 0)
					{
						result[i].replace(result[i].size() - 1, result[i].size(), "");
					}
				}
				startPos++;
				endPos++;
			}
			wancheng = true;
		}
		else
		{
			result[0] = "0";
			wancheng = true;
		}

		return result;
	}



	//std::string Gettmpstring(std::string line, std::string beginFlag, std::string endFlag)
	//{
	//	std::string linsu;
	//	int startPos = 0;
	//	int endPos = 0;
	//	int beginPos = 0;
	//	int endingpos = 0;
	//	startPos = (int)line.find(beginFlag, startPos);
	//	endPos = (int)line.find(endFlag, startPos + 1);
	//	beginPos = startPos + (int)beginFlag.length();
	//	endingpos = endPos - startPos - (int)beginFlag.length();
	//	return line.substr(beginPos, endingpos);
	//}

	//std::string * Getiads(std::string line, std::string beginFlag, std::string endFlag, std::string end)
	//{
	//	std::string *linsu = new std::string[15];
	//	int startPos = 0;
	//	int endPos = 0;
	//	int beginPos = 0;
	//	int endingpos = 0;
	//	for (int i = 0; i < 15; i++)
	//	{
	//		startPos = (int)line.find(beginFlag, startPos);
	//		endPos = (int)line.find(endFlag, startPos);
	//		beginPos = startPos + (int)beginFlag.length() + 3;
	//		endingpos = endPos - startPos - (int)beginFlag.length() - 3;
	//		linsu[i] = line.substr(beginPos, endingpos);
	//		if ((int)linsu[i].find(end) > 0)
	//		{
	//			linsu[i].replace(linsu[i].size() - 1, linsu[i].size(), "");
	//			if ((int)linsu[i].find(end) > 0)
	//			{
	//				linsu[i].replace(linsu[i].size() - 1, linsu[i].size(), "");
	//			}
	//		}
	//		if (linsu[i].size() > 5)
	//		{
	//			linsu[i] = "";
	//			break;
	//		}
	//		startPos++;
	//		endPos++;
	//	}
	//	return linsu;
	//}

	//void getTomorrowids()
	//{
	//	shu = 0;
	//	wancheng_t = false;
	//	std::string retVal;
	//	const auto handle = InternetOpen(L"GetTomorrowID", INTERNET_OPEN_TYPE_PRECONFIG, nullptr, nullptr, 0);
	//	if (handle == nullptr)
	//	{
	//		InternetCloseHandle(handle);
	//		
	//		geting_t = false;
	//		wancheng_t = true;
	//	}
	//	std::string _a = "https://api.guildwars2.com/v2/achievements/daily/tomorrow";
	//	LPCWSTR ul = stringToLPCWSTR(_a);

	//	const auto request = InternetOpenUrl(handle, ul, nullptr, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
	//	//delete(ul);

	//	if (request == nullptr)
	//	{
	//		InternetCloseHandle(request);
	//		
	//		geting_t = false;
	//		wancheng_t = true;
	//	}
	//	char response_data[10240];//������
	//	DWORD response_length = 0;

	//	if (InternetReadFile(request, response_data, sizeof(response_data) - 1, &response_length) && response_length > 0)
	//	{
	//		response_data[response_length] = '\0';
	//		response_length++;
	//	}
	//	InternetCloseHandle(request);
	//	InternetCloseHandle(handle);
	//	retVal = response_data;
	//	std::string* pvetmpID = new std::string[16];
	//	std::string* pvptmpID = new std::string[5];
	//	std::string* wvwtmpID = new std::string[5];
	//	std::string* ftstmpID = new std::string[16];
	//	std::string pve;
	//	std::string pvp;
	//	std::string wvw;
	//	std::string fts;
	//	if (retVal.size()>4000)
	//	{
	//		//std::cout << " retVal.size is " << retVal.size() << std::endl;
	//		pve = Gettmpstring(retVal, pvebeginFlag, pvpbeginFlag);
	//		//std::cout << " pve.size is " << pve.size() << std::endl;
	//		pvp = Gettmpstring(retVal, pvpbeginFlag, wvwbeginFlag);
	//		//std::cout << " pvp.size is " << pvp.size() << std::endl;
	//		wvw = Gettmpstring(retVal, wvwbeginFlag, ftsbeginFlag);
	//		//std::cout << " wvw.size is " << wvw.size() << std::endl;
	//		fts = Gettmpstring(retVal, ftsbeginFlag, end2Flag);
	//		//std::cout << " fts.size is " << fts.size() << std::endl;
	//		pvetmpID = Getiads(pve, beginFlag, endFlag, end);
	//		pvptmpID = Getiads(pvp, beginFlag, endFlag, end);
	//		wvwtmpID = Getiads(wvw, beginFlag, endFlag, end);
	//		ftstmpID = Getiads(fts, beginFlag, endFlag, end);
	//		for (int i = 0; i < 15; i++)
	//		{
	//			if (pvetmpID[i].size() == 0)
	//			{
	//				break;
	//			}
	//			shu++;
	//			Tomorrowids_ += pvetmpID[i] + ",";
	//		}
	//		for (int i = 0; i < 15; i++)
	//		{
	//			if (pvptmpID[i].size() == 0)
	//			{
	//				break;
	//			}
	//			shu++;
	//			Tomorrowids_ += pvptmpID[i] + ",";
	//		}
	//		for (int i = 0; i < 15; i++)
	//		{
	//			if (wvwtmpID[i].size() == 0)
	//			{
	//				break;
	//			}
	//			shu++;
	//			Tomorrowids_ += wvwtmpID[i] + ",";
	//		}
	//		for (int i = 0; i < 15; i++)
	//		{
	//			if (ftstmpID[i].size() == 0)
	//			{
	//				break;
	//			}
	//			if ((i == 0) || (i == 1) || (i == 2) || (i == 6) || (i == 10) || (i == 14))
	//			{
	//				shu++;
	//				Tomorrowids_ += ftstmpID[i] + ",";
	//			}
	//		}

	//		//std::cout << " Tomorrowids_ is " << Tomorrowids_ << std::endl;

	//		getTomorrownames(Tomorrowids_);
	//	}
	//	else
	//	{
	//		pve = ""; pvp = ""; wvw = ""; fts = "";
	//		Tomorrowids_ = "";
	//	}
	//	wancheng_t = true;
	//	//return retVal;
	//}
	////Tomorrow
	//void getTomorrownames(std::string date)
	//{
	//	A_ = 0;
	//	
	//	zhengshu = 0;//��ʵ����
	//	wancheng_t_n = false;
	//	std::string retVal;
	//	const auto handle1 = InternetOpen(L"GetTomorrownames", INTERNET_OPEN_TYPE_PRECONFIG, nullptr, nullptr, 0);
	//	if (handle1 == nullptr)
	//	{
	//		InternetCloseHandle(handle1);
	//		geting_t_n = false;
	//		wancheng_t_n = true;
	//	}
	//	std::string _a = "https://api.guildwars2.com/v2/achievements?lang=zh&ids=";
	//	std::string _b = date;
	//	std::string _tmp = _a + _b;
	//	LPCWSTR ul1 = stringToLPCWSTR(_tmp);

	//	try
	//	{
	//		/*const auto request1 = InternetOpenUrl(handle1, ul1, nullptr, 0, INTERNET_FLAG_RELOAD, 0);*/


	//		if (const auto request1 = InternetOpenUrl(handle1, ul1, nullptr, 0, 0, 0))
	//		{
	//			if (request1 == nullptr)
	//			{
	//				InternetCloseHandle(request1);
	//				geting_t_n = false;
	//				wancheng_t_n = true;
	//			}
	//			char response_data[20480];//������
	//			DWORD response_length = 0;
	//			if (InternetReadFile(request1, response_data, sizeof(response_data) - 1, &response_length) && response_length > 0)
	//			{
	//				response_data[response_length] = '\0';
	//				response_length++;
	//			}
	//			InternetCloseHandle(request1);
	//			InternetCloseHandle(handle1);
	//			retVal = response_data;
	//		}
	//		else
	//		{
	//			retVal = "";
	//		}
	//	}
	//	catch (...)
	//	{
	//		retVal = "";
	//	}

	//	if (retVal != "")
	//	{
	//		std::string beginFlag_ = u8"name";
	//		std::string endFlag_ = u8",";
	//		std::string end_ = u8"}";
	//		int startPos_ = 0;
	//		int endPos_ = 0;
	//		int beginPos_ = 0;
	//		int endingpos_ = 0;
	//		int shus_ = shu + 1;
	//		//std::cout << shu << std::endl;
	//		for (int i = 0; i < shus_; i++)
	//		{
	//			startPos_ = (int)retVal.find(beginFlag_, startPos_);
	//			endPos_ = (int)retVal.find(endFlag_, startPos_);
	//			beginPos_ = startPos_ + (int)beginFlag_.length() + 2;
	//			endingpos_ = endPos_ - startPos_ - (int)beginFlag_.length() - 2;
	//			tmpIDname[i] = retVal.substr(beginPos_, endingpos_);
	//			if ((int)tmpIDname[i].find(end) > 0)
	//			{
	//				tmpIDname[i].replace(tmpIDname[i].size() - 1, tmpIDname[i].size(), "");
	//				if ((int)tmpIDname[i].find(end) > 0)
	//				{
	//					tmpIDname[i].replace(tmpIDname[i].size() - 1, tmpIDname[i].size(), "");
	//				}
	//			}

	//			if (tmpIDname[i].size() > 120)
	//			{
	//				tmpIDname[i] = "";
	//				break;
	//			}
	//			else
	//			{
	//				zhengshu++;
	//			}
	//			//std::cout << zhengshu << std::endl;
	//			//std::cout << " tmpIDname[i] is " << tmpIDname[i] << std::endl;
	//			//log.AddLog(tmpIDname[i].c_str());
	//			startPos_++;
	//			endPos_++;

	//		}

	//		int B_ = 0;
	//		int C_ = 0;
	//		int D_ = 0;
	//		for (int i = 0; i < zhengshu; i++)
	//		{
	//			if (i < (zhengshu - 6 - 4 - 4))
	//			{
	//				PVEname[A_++] = tmpIDname[i];
	//			}
	//			else
	//			{
	//				if (i < (zhengshu - 6 - 4))
	//				{
	//					PVPname[B_++] = tmpIDname[i];
	//				}
	//				else
	//				{
	//					if (i < (zhengshu - 6))
	//					{
	//						WVWname[C_++] = tmpIDname[i];
	//					}
	//					else
	//					{
	//						if (i < (zhengshu))
	//						{
	//							FTSname[D_++] = tmpIDname[i];
	//						}
	//					}
	//				}
	//			}
	//		}
	//		
	//	}
	//	wancheng_t_n = true;
	//}


	void getsting(const char *  days)
	{
		geting = false;
		W_renwu1 = FetchReleaseData(days);
	}

	//void getTomorrowsting(int a)
	//{
	//	geting_t = false;
	//	//Tomorrowids = getTomorrowids();
	//	getTomorrowids();
	//}

#pragma endregion

	bool BossTime::_DoUI(bool &ison)
	{
		if (ison)
		{
			//ImFontAtlas* atlas = ImGui::GetIO().Fonts;
			ImGui::SetNextWindowBgAlpha(0.4f);
			//ImGui::GetIO().FontGlobalScale = 1.5f;
			
			ImGui::Begin(u8"BOSS��ʱ��", &ison, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
			const float spacing = ImGui::GetStyle().ItemInnerSpacing.x;
			static int lines = 3;
		    float daxiao_ = MiscTab::i()->jiemiandaxiao();
			//ImGui::SliderFloat("Value", &daxiao_, 1.0f, 3.0f);
			ImGui::SetWindowFontScale(daxiao_); /////


			//ImGui::GetIO().FontGlobalScale= 2.0f;
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 5));
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(1, 1));
			ImGui::BeginChild("scrolling", ImVec2(247* daxiao_, 65* daxiao_), false);
			ImGui::SetWindowFontScale(daxiao_);/////
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
					if (ImGui::Button(label, ImVec2(82.0f* daxiao_, 19 * daxiao_)))
					{
						ImGui::SetClipboardText(Bosstm(line, n));
					}
					ImGui::PopStyleColor(3);
					ImGui::PopID();
				}
			}
			scroll_x = ImGui::GetScrollX();
			ImGui::EndChild();
			time_t time_seconds = time(0);
			tm now_time;
			localtime_s(&now_time, &time_seconds);

			if (MiscTab::i()->getweb())
			{
				if (geting)
				{
					W_time1 = GetTime(0);
					boost::thread(&getsting, W_time1);
				}
			}
			//if (SettingsMenu::i()->getmingtian())
			//{
			//	if (geting_t)
			//	{
			//		boost::thread(&getTomorrowsting, 0);
			//	}
			//}


			float scroll_x_delta = 0.0f;
			if (ImGui::GetIO().WantCaptureMouse == 1)
			{

				ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(scroll_x / 82 / daxiao_ * 0.02083f, 0.6f, 0.6f, 0.44f));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(scroll_x / 82 / daxiao_ * 0.02083f, 0.6f, 0.6f, 0.44f));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(scroll_x / 82 / daxiao_ * 0.02083f, 0.6f, 0.6f, 0.44f));
				if (ImGui::SmallButton("<<------------------"))scroll_x_delta = -82 * daxiao_; ImGui::SameLine();
				if (ImGui::SmallButton(u8"�� ��")) ison = false; ImGui::SameLine();
				if (ImGui::SmallButton("------------------>>"))scroll_x_delta = +82 * daxiao_; ImGui::SameLine();
				ImGui::PopStyleColor(3);
				if (scroll_x_delta != 0.0f)ImGui::BeginChild("scrolling"), ImGui::SetScrollX(ImGui::GetScrollX() + scroll_x_delta), ImGui::EndChild();
				//==
				ImGui::AlignTextToFramePadding();
				ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());
				if (MiscTab::i()->getweb())
				{
					//if (geting)
					//{
					//	W_time1 = GetTime(0);
					//	boost::thread(&getsting, W_time1);
					//}
					//else
					{
						ImGui::Spacing();


						bool node_open = ImGui::TreeNode(u8"��ҳ�ճ�", u8"��ҳ�ճ� : (%s)", W_time1);
						ImGui::SameLine(180.0f* daxiao_, spacing);
						ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(scroll_x / 82/ daxiao_ * 0.02083f, 0.6f, 0.6f, 0.44f));
						ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(scroll_x / 82 / daxiao_ * 0.02083f, 0.6f, 0.6f, 0.44f));
						ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(scroll_x / 82 / daxiao_ * 0.02083f, 0.6f, 0.6f, 0.44f));
						if (ImGui::SmallButton(u8"����"))
						{
							if (wancheng)
							{
								if (days == 0)
								{
									for (int i = 0; i < 5; i++)
									{
										W_renwu2[i] = W_renwu1[i];
									}

									W_time2 = W_time1;

								}
								days++;
								const char *  addday = GetTime(days);
								W_time1 = addday;
								//log.AddLog(W_time1);//��־
								boost::thread(&getsting, addday);
							}

						}
						ImGui::SameLine(210.0f* daxiao_, spacing);
						if (ImGui::SmallButton(u8"����"))
						{
							std::string arrc1 = u8" ����ҳ����: ";
							std::string arrc12 = W_time1;
							std::string arrc2 = u8"����\"gw2sy.top\"����boss��ʾ��";
							std::string arrc3 = u8"--";
							std::string r1 = u8"����һ:";
							std::string r2 = u8"�����:";
							std::string r3 = u8"������:";
							std::string r4 = u8"������:";
							std::string r5 = u8"������:";
							std::string r6 = "\r\n";
							if (W_renwu1[0] != "0")
							{
								W_arrc = (arrc12 + arrc1 + r6 + r1 + W_renwu1[0] + r6 + r2 + W_renwu1[1] + r6 + r3 + W_renwu1[2] + r6 + r4 + W_renwu1[3] + r6 + r5 + W_renwu1[4] + r6 + arrc2).c_str();
								ImGui::SetClipboardText(W_arrc);
							}
							else
							{
								ImGui::SetClipboardText("");
							}

						}
						if (node_open)
						{
							if (wancheng)
							{
								if (W_renwu1[0] != "0")
								{
									for (int i = 0; i < 5; i++)
									{
										ImGui::Text(W_renwu1[i].c_str());
									}
									ImGui::TreePop();
								}
								else
								{
									ImGui::Text(u8"-----δ��ȡ����Ϣ��ȴ���������1-----");
									ImGui::TreePop();
								}
							}
							else
							{
								ImGui::Text(u8"-----���ڻ�ȡ�������ĵȺ�-----");
								ImGui::TreePop();
							}
						}
						ImGui::PopStyleColor(3);
					}	
				}
				//if (SettingsMenu::i()->getmingtian())
				//{
				//	//if (geting_t)
				//	//{
				//	//	boost::thread(&getTomorrowsting, 0);
				//	//}
				//	//else
				//	{
				//		if (wancheng_t_n)
				//		{
				//			ImGui::Spacing();
				//			bool node_open2 = ImGui::TreeNode(u8"������ճ�");
				//			if (node_open2)
				//			{
				//				if (PVEname[0].size() > 1)
				//				{
				//					ImGui::BeginTabBar(u8"������ճ�", ImGuiTabBarFlags_None);
				//					if (ImGui::BeginTabItem(u8"PVE�ճ�"))//++
				//					{
				//						for (int i = 0; i < A_; i++)
				//						{
				//							if (PVEname[i].size() > 1)
				//							{
				//								ImGui::Text(PVEname[i].c_str());
				//							}
				//						}
				//						ImGui::EndTabItem();//++
				//					};
				//					if (ImGui::BeginTabItem(u8"PVP�ճ�"))//++
				//					{
				//						for (int i = 0; i < 4; i++)
				//						{
				//							if (PVPname[i].size() > 1)
				//							{
				//								ImGui::Text(PVPname[i].c_str());
				//							}
				//						}
				//						ImGui::EndTabItem();//++
				//					};
				//					if (ImGui::BeginTabItem(u8"WVW�ճ�"))//++
				//					{
				//						for (int i = 0; i < 4; i++)
				//						{
				//							if (WVWname[i].size() > 1)
				//							{
				//								ImGui::Text(WVWname[i].c_str());
				//							}
				//						}
				//						ImGui::EndTabItem();//++
				//					};
				//					if (ImGui::BeginTabItem(u8"����ճ�"))//++
				//					{
				//						for (int i = 0; i < 6; i++)
				//						{
				//							if (FTSname[i].size() > 1)
				//							{
				//								ImGui::Text(FTSname[i].c_str());
				//							}
				//						}
				//						
				//						ImGui::EndTabItem();//++
				//					};

				//					ImGui::EndTabBar();//++
				//				}
				//				else
				//				{
				//					ImGui::Text(u8"��ȡ��Ϣʧ��,\r\n��鿴�����Ƿ������������ٷ�api\r\n�������´���Ϸ\r\n");
				//				}
				//				
				//			}

				//		}
				//	}
				//}
			}
			else
			{
				ImGui::BeginChild("scrolling");
				if (now_time.tm_hour * 60 + now_time.tm_min < 30)
				{
					ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15) * 82.0f* daxiao_);
				}
				else
				{
					ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15 - 1) * 82.0f* daxiao_);
				}
				ImGui::EndChild();
				if (MiscTab::i()->getweb())
				{
					if (wancheng)
					{
						if (days != 0)
						{
							days = 0;
							W_time1 = W_time2;
							for (int i = 0; i < 5; i++)
							{
								W_renwu1[i] = W_renwu2[i];
							}
						}
						if (!ghen&&now_time.tm_hour == 0 && now_time.tm_min == 0) 
						{
							ghen = true;
							const char *  adddayend = GetTime(0);
							if (W_time1 != adddayend)
							{
								W_time1 = adddayend;
								boost::thread(&getsting, adddayend);
								//if (SettingsMenu::i()->getmingtian())
								//{
								//	//std::cout << zhengshu << std::endl;
								//	boost::thread(&getTomorrowsting, 0);
								//}
							}
						}
					}
				}
				else
				{
					//if (SettingsMenu::i()->getmingtian())
					//{
					//	if (!ghen)
					//	{
					//		if (now_time.tm_hour == 0 && now_time.tm_min == 0)
					//		{
					//			ghen = true;
					//			boost::thread(&getTomorrowsting, 0);
					//		}
					//	}
					//}
				}
			}
			ImGui::End();
			ImGui::PopStyleVar(4);
		}

		//log.Draw(u8"Log", &is);//��־��ʾ
		return ison;



	}

	InputResponse BossTime::OnInputChangeweb(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		const bool isMenuKeybindweb = keys == showKeybindweb_.keys();
		if (isMenuKeybindweb)
		{
			kput = 1;
			if (jishiqi)
			{
				isVisibleweb_ = true;
				jishiqi = false;
			}
			else
			{
				isVisibleweb_ = false;
				jishiqi = true;
			}
		}
		return isMenuKeybindweb ? InputResponse::PREVENT_ALL : InputResponse::PASS_TO_GAME;
	}


}
