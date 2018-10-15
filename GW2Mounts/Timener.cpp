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
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [0:00] 来自神油BOSS提示器";
        case 1:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [0:15] 来自神油BOSS提示器";
        case 2:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [0:30] 来自神油BOSS提示器";
        case 3:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [0:45] 来自神油BOSS提示器";
        case 4:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [1:00] 来自神油BOSS提示器";
        case 5:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [1:15] 来自神油BOSS提示器";
        case 6:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [1:30] 来自神油BOSS提示器";
        case 7:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [1:45] 来自神油BOSS提示器";
        case 8:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [2:00] 来自神油BOSS提示器";
        case 9:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [2:15] 来自神油BOSS提示器";
        case 10:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [2:30] 来自神油BOSS提示器";
        case 11:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [2:45] 来自神油BOSS提示器";
        case 12:
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [3:00] 来自神油BOSS提示器";
        case 13:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [3:15] 来自神油BOSS提示器";
        case 14:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [3:30] 来自神油BOSS提示器";
        case 15:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [3:45] 来自神油BOSS提示器";
        case 16:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [4:00] 来自神油BOSS提示器";
        case 17:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [4:15] 来自神油BOSS提示器";
        case 18:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [4:30] 来自神油BOSS提示器";
        case 19:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [4:45] 来自神油BOSS提示器";
        case 20:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [5:00] 来自神油BOSS提示器";
        case 21:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [5:15] 来自神油BOSS提示器";
        case 22:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [5:30] 来自神油BOSS提示器";
        case 23:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [5:45] 来自神油BOSS提示器";
        case 24:
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [6:00] 来自神油BOSS提示器";
        case 25:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [6:15] 来自神油BOSS提示器";
        case 26:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [6:30] 来自神油BOSS提示器";
        case 27:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [6:45] 来自神油BOSS提示器";
        case 28:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [7:00] 来自神油BOSS提示器";
        case 29:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [7:15] 来自神油BOSS提示器";
        case 30:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [7:30] 来自神油BOSS提示器";
        case 31:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [7:45] 来自神油BOSS提示器";
        case 32:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [8:00] 来自神油BOSS提示器";
        case 33:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [8:15] 来自神油BOSS提示器";
        case 34:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [8:30] 来自神油BOSS提示器";
        case 35:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [8:45] 来自神油BOSS提示器";
        case 36:
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [9:00] 来自神油BOSS提示器";
        case 37:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [9:15] 来自神油BOSS提示器";
        case 38:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [9:30] 来自神油BOSS提示器";
        case 39:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [9:45] 来自神油BOSS提示器";
        case 40:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [10:00] 来自神油BOSS提示器";
        case 41:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [10:15] 来自神油BOSS提示器";
        case 42:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [10:30] 来自神油BOSS提示器";
        case 43:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [10:45] 来自神油BOSS提示器";
        case 44:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [11:00] 来自神油BOSS提示器";
        case 45:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [11:15] 来自神油BOSS提示器";
        case 46:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [11:30] 来自神油BOSS提示器";
        case 47:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [11:45] 来自神油BOSS提示器";
        case 48:
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [12:00] 来自神油BOSS提示器";
        case 49:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [12:15] 来自神油BOSS提示器";
        case 50:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [12:30] 来自神油BOSS提示器";
        case 51:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [12:45] 来自神油BOSS提示器";
        case 52:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [13:00] 来自神油BOSS提示器";
        case 53:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [13:15] 来自神油BOSS提示器";
        case 54:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [13:30] 来自神油BOSS提示器";
        case 55:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [13:45] 来自神油BOSS提示器";
        case 56:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [14:00] 来自神油BOSS提示器";
        case 57:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [14:15] 来自神油BOSS提示器";
        case 58:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [14:30] 来自神油BOSS提示器";
        case 59:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [14:45] 来自神油BOSS提示器";
        case 60:
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [15:00] 来自神油BOSS提示器";
        case 61:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [15:15] 来自神油BOSS提示器";
        case 62:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [15:30] 来自神油BOSS提示器";
        case 63:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [15:45] 来自神油BOSS提示器";
        case 64:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [16:00] 来自神油BOSS提示器";
        case 65:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [16:15] 来自神油BOSS提示器";
        case 66:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [16:30] 来自神油BOSS提示器";
        case 67:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [16:45] 来自神油BOSS提示器";
        case 68:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [17:00] 来自神油BOSS提示器";
        case 69:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [17:15] 来自神油BOSS提示器";
        case 70:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [17:30] 来自神油BOSS提示器";
        case 71:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [17:45] 来自神油BOSS提示器";
        case 72:
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [18:00] 来自神油BOSS提示器";
        case 73:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [18:15] 来自神油BOSS提示器";
        case 74:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [18:30] 来自神油BOSS提示器";
        case 75:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [18:45] 来自神油BOSS提示器";
        case 76:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [19:00] 来自神油BOSS提示器";
        case 77:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [19:15] 来自神油BOSS提示器";
        case 78:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [19:30] 来自神油BOSS提示器";
        case 79:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [19:45] 来自神油BOSS提示器";
        case 80:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [20:00] 来自神油BOSS提示器";
        case 81:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [20:15] 来自神油BOSS提示器";
        case 82:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [20:30] 来自神油BOSS提示器";
        case 83:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [20:45] 来自神油BOSS提示器";
        case 84:
            return u8"世界BOSS提醒 <<碎裂巨兽 >>[&BE4DAAA=] [21:00] 来自神油BOSS提示器";
        case 85:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [21:15] 来自神油BOSS提示器";
        case 86:
            return u8"世界BOSS提醒 <<人马王 >>[&BLEAAAA=] [21:30] 来自神油BOSS提示器";
        case 87:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [21:45] 来自神油BOSS提示器";
        case 88:
            return u8"世界BOSS提醒 <<魔像 >>[&BNQCAAA=] [22:00] 来自神油BOSS提示器";
        case 89:
            return u8"世界BOSS提醒 <<冰萨满 >>[&BH4BAAA=] [22:15] 来自神油BOSS提示器";
        case 90:
            return u8"世界BOSS提醒 <<卓玛 >>[&BHoCAAA=] [22:30] 来自神油BOSS提示器";
        case 91:
            return u8"世界BOSS提醒 <<火元素 >>[&BEYAAAA=] [22:45] 来自神油BOSS提示器";
        case 92:
            return u8"世界BOSS提醒 <<科文顿 >>[&BKgBAAA=] [23:00] 来自神油BOSS提示器";
        case 93:
            return u8"世界BOSS提醒 <<林地虫 >>[&BEEFAAA=] [23:15] 来自神油BOSS提示器";
        case 94:
            return u8"世界BOSS提醒 <<超能毁灭 >>[&BM0CAAA=] [23:30] 来自神油BOSS提示器";
        case 95:
            return u8"世界BOSS提醒 <<暗影巨兽 >>[&BPwAAAA=] [23:45] 来自神油BOSS提示器";
        default:
            return u8"未知错误";
        }
    }
    if (a == 1)
    {
        switch (b)
        {
        case 0:
            return u8"世界BOSS提醒 <<僵尸龙>> [&BNABAAA=] [0:00] 来自神油BOSS提示器";
        case 1:
            return u8"当前事件 甘达拉战区 跑男 [&BJEBAAA=] [0:20] 来自神油BOSS提示器";
        case 2:
            return u8"当前事件 阿斯福德平原 度量领域 卡尔顿之森 [0:30] 来自神油BOSS提示器";
        case 3:
            return u8"";
        case 4:
            return u8"世界BOSS提醒 <<三重麻烦>> [&BKoBAAA=] [1:00] 来自神油BOSS提示器";
        case 5:
            return u8"";
        case 6:
            return u8"当前事件 女王谷 甘达拉战区 卡尔顿之森 [1:30] 来自神油BOSS提示器";
        case 7:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [1:45] 来自神油BOSS提示器";
        case 8:
            return u8"";
        case 9:
            return u8"当前事件 林线瀑布 跑男 [&BEYEAAA=] [2:20] 来自神油BOSS提示器";
        case 10:
            return u8"当前事件 女王谷 旅者丘陵 度量领域 [2:30] 来自神油BOSS提示器";
        case 11:
            return u8"";
        case 12:
            return u8"世界BOSS提醒 <<喀壳虫女王>> [&BNcGAAA=] [3:00] 来自神油BOSS提示器";
        case 13:
            return u8"";
        case 14:
            return u8"当前事件 旅者丘陵 阿斯福德平原 卡尔顿之森 [3:30] 来自神油BOSS提示器";
        case 15:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [3:45] 来自神油BOSS提示器";
        case 16:
            return u8"世界BOSS提醒 <<僵尸龙>> [&BNABAAA=] [4:00] 来自神油BOSS提示器";
        case 17:
            return u8"当前事件 钢铁平原 跑男 [&BOkBAAA=] [4:20] 来自神油BOSS提示器";
        case 18:
            return u8"当前事件 女王谷 阿斯福德平原 甘达拉战区 [4:30] 来自神油BOSS提示器";
        case 19:
            return u8"";
        case 20:
            return u8"世界BOSS提醒 <<三重麻烦>> [&BKoBAAA=] [5:00] 来自神油BOSS提示器";
        case 21:
            return u8"";
        case 22:
            return u8"当前事件 旅者丘陵 甘达拉战区 度量领域 [5:30] 来自神油BOSS提示器";
        case 23:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [5:45] 来自神油BOSS提示器";
        case 24:
            return u8"";
        case 25:
            return u8"当前事件 甘达拉战区 跑男 [&BJEBAAA=] [6:20] 来自神油BOSS提示器";
        case 26:
            return u8"当前事件 阿斯福德平原 度量领域 卡尔顿之森 [6:30] 来自神油BOSS提示器";
        case 27:
            return u8"";
        case 28:
            return u8"世界BOSS提醒 <<喀壳虫女王>> [&BNcGAAA=] [7:00] 来自神油BOSS提示器";
        case 29:
            return u8"";
        case 30:
            return u8"当前事件 女王谷 甘达拉战区 卡尔顿之森 [7:30] 来自神油BOSS提示器";
        case 31:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [7:45] 来自神油BOSS提示器";
        case 32:
            return u8"世界BOSS提醒 <<僵尸龙>> [&BNABAAA=] [8:00] 来自神油BOSS提示器";
        case 33:
            return u8"当前事件 林线瀑布 跑男 [&BEYEAAA=] [8:20] 来自神油BOSS提示器";
        case 34:
            return u8"当前事件 女王谷 旅者丘陵 度量领域 [8:30] 来自神油BOSS提示器";
        case 35:
            return u8"";
        case 36:
            return u8"世界BOSS提醒 <<三重麻烦>> [&BKoBAAA=] [9:00] 来自神油BOSS提示器";
        case 37:
            return u8"";
        case 38:
            return u8"当前事件 旅者丘陵 阿斯福德平原 卡尔顿之森 [9:30] 来自神油BOSS提示器";
        case 39:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [9:45] 来自神油BOSS提示器";
        case 40:
            return u8"世界BOSS提醒 <<喀壳虫女王>> [&BNcGAAA=] [10:00] 来自神油BOSS提示器";
        case 41:
            return u8"当前事件 钢铁平原 跑男 [&BOkBAAA=] [10:20] 来自神油BOSS提示器";
        case 42:
            return u8"当前事件 女王谷 阿斯福德平原 甘达拉战区 [10:30] 来自神油BOSS提示器";
        case 43:
            return u8"";
        case 44:
            return u8"世界BOSS提醒 <<僵尸龙>> [&BNABAAA=] [11:00] 来自神油BOSS提示器";
        case 45:
            return u8"";
        case 46:
            return u8"当前事件 旅者丘陵 甘达拉战区 度量领域 [11:30] 来自神油BOSS提示器";
        case 47:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [11:45] 来自神油BOSS提示器";
        case 48:
            return u8"世界BOSS提醒 <<三重麻烦>> [&BKoBAAA=] [12:00] 来自神油BOSS提示器";
        case 49:
            return u8"当前事件 甘达拉战区 跑男 [&BJEBAAA=] [12:20] 来自神油BOSS提示器";
        case 50:
            return u8"当前事件 阿斯福德平原 度量领域 卡尔顿之森 [12:30] 来自神油BOSS提示器";
        case 51:
            return u8"";
        case 52:
            return u8"";
        case 53:
            return u8"";
        case 54:
            return u8"当前事件 女王谷 甘达拉战区 卡尔顿之森 [13:30] 来自神油BOSS提示器";
        case 55:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [13:45] 来自神油BOSS提示器";
        case 56:
            return u8"世界BOSS提醒 <<喀壳虫女王>> [&BNcGAAA=] [14:00] 来自神油BOSS提示器";
        case 57:
            return u8"当前事件 林线瀑布 跑男 [&BEYEAAA=] [14:20] 来自神油BOSS提示器";
        case 58:
            return u8"当前事件 女王谷 旅者丘陵 度量领域 [14:30] 来自神油BOSS提示器";
        case 59:
            return u8"";
        case 60:
            return u8"世界BOSS提醒 <<僵尸龙>> [&BNABAAA=] [15:00] 来自神油BOSS提示器";
        case 61:
            return u8"";
        case 62:
            return u8"当前事件 旅者丘陵 阿斯福德平原 卡尔顿之森 [15:30] 来自神油BOSS提示器";
        case 63:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [15:45] 来自神油BOSS提示器";
        case 64:
            return u8"世界BOSS提醒 <<三重麻烦>> [&BKoBAAA=] [16:00] 来自神油BOSS提示器";
        case 65:
            return u8"当前事件 钢铁平原 跑男 [&BOkBAAA=] [16:20] 来自神油BOSS提示器";
        case 66:
            return u8"当前事件 女王谷 阿斯福德平原 甘达拉战区 16:30] 来自神油BOSS提示器";
        case 67:
            return u8"";
        case 68:
            return u8"";
        case 69:
            return u8"";
        case 70:
            return u8"当前事件 旅者丘陵 甘达拉战区 度量领域 [17:30] 来自神油BOSS提示器";
        case 71:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [17:45] 来自神油BOSS提示器";
        case 72:
            return u8"";
        case 73:
            return u8"当前事件 甘达拉战区 跑男 [&BJEBAAA=] [18:20] 来自神油BOSS提示器";
        case 74:
            return u8"世界BOSS提醒 <<喀壳虫女王>> [&BNcGAAA=] [18:30] 来自神油BOSS提示器";
        case 75:
            return u8"当前事件 阿斯福德平原 度量领域 卡尔顿之森 [18:30] 来自神油BOSS提示器";
        case 76:
            return u8"";
        case 77:
            return u8"";
        case 78:
            return u8"世界BOSS提醒 <<僵尸龙>> [&BNABAAA=] [19:30] 来自神油BOSS提示器";
        case 79:
            return u8"当前事件 女王谷 甘达拉战区 卡尔顿之森 [19:30] 来自神油BOSS提示器";
        case 80:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [19:45] 来自神油BOSS提示器";
        case 81:
            return u8"当前事件 林线瀑布 跑男 [&BEYEAAA=] [20:20] 来自神油BOSS提示器";
        case 82:
            return u8"世界BOSS提醒 <<三重麻烦>> [&BKoBAAA=] [20:30]  来自神油BOSS提示器";
        case 83:
            return u8"当前事件 女王谷 旅者丘陵 度量领域 [20:30] 来自神油BOSS提示器";
        case 84:
            return u8"";
        case 85:
            return u8"";
        case 86:
            return u8"当前事件 旅者丘陵 阿斯福德平原 卡尔顿之森 [21:30] 来自神油BOSS提示器";
        case 87:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [21:45] 来自神油BOSS提示器";
        case 88:
            return u8"";
        case 89:
            return u8"当前事件 钢铁平原 跑男 [&BOkBAAA=] [22:20] 来自神油BOSS提示器";
        case 90:
            return u8"当前事件 女王谷 阿斯福德平原 甘达拉战区 [22:30] 来自神油BOSS提示器";
        case 91:
            return u8"";
        case 92:
            return u8"世界BOSS提醒 <<喀壳虫女王>> [&BNcGAAA=] [23:00] 来自神油BOSS提示器";
        case 93:
            return u8"";
        case 94:
            return u8"当前事件 旅者丘陵 甘达拉战区 度量领域 [23:30] 来自神油BOSS提示器";
        case 95:
            return u8"大型事件提醒 帕拉瓦 [&BPcKAAA=] [23:45] 来自神油BOSS提示器";
        default:
            return u8"未知错误";
        }
    }
    if (a == 2)
    {
        switch (b)
        {
        case 0:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [0:05] 来自神油BOSS提示器";
        case 1:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [0:10] 来自神油BOSS提示器";
        case 2:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [0:30] 来自神油BOSS提示器";
        case 3:
            return u8"";
        case 4:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [1:00] 来自神油BOSS提示器";
        case 5:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [1:00] 来自神油BOSS提示器";
        case 6:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [1:30] 来自神油BOSS提示器";
        case 7:
            return u8"";
        case 8:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [2:05] 来自神油BOSS提示器";
        case 9:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [2:10] 来自神油BOSS提示器";
        case 10:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [2:30] 来自神油BOSS提示器";
        case 11:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [2:30] 来自神油BOSS提示器";
        case 12:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [3:00] 来自神油BOSS提示器";
        case 13:
            return u8"";
        case 14:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [3:30] 来自神油BOSS提示器";
        case 15:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [4:00] 来自神油BOSS提示器";
        case 16:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [4:05] 来自神油BOSS提示器";
        case 17:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [4:10] 来自神油BOSS提示器";
        case 18:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [4:30] 来自神油BOSS提示器";
        case 19:
            return u8"";
        case 20:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [5:00] 来自神油BOSS提示器";
        case 21:
            return u8"";
        case 22:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [5:30] 来自神油BOSS提示器";
        case 23:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [5:30] 来自神油BOSS提示器";
        case 24:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [6:05] 来自神油BOSS提示器";
        case 25:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [6:10] 来自神油BOSS提示器";
        case 26:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [6:30] 来自神油BOSS提示器";
        case 27:
            return u8"";
        case 28:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [7:00] 来自神油BOSS提示器";
        case 29:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [7:00] 来自神油BOSS提示器";
        case 30:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [7:30] 来自神油BOSS提示器";
        case 31:
            return u8"";
        case 32:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [8:05] 来自神油BOSS提示器";
        case 33:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [8:10] 来自神油BOSS提示器";
        case 34:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [8:30] 来自神油BOSS提示器";
        case 35:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [8:30] 来自神油BOSS提示器";
        case 36:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [9:00] 来自神油BOSS提示器";
        case 37:
            return u8"";
        case 38:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [9:30] 来自神油BOSS提示器";
        case 39:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [10:00] 来自神油BOSS提示器";
        case 40:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [10:05] 来自神油BOSS提示器";
        case 41:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [10:10] 来自神油BOSS提示器";
        case 42:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [10:30] 来自神油BOSS提示器";
        case 43:
            return u8"";
        case 44:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [11:00] 来自神油BOSS提示器";
        case 45:
            return u8"";
        case 46:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [11:30] 来自神油BOSS提示器";
        case 47:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [11:30] 来自神油BOSS提示器";
        case 48:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [12:05] 来自神油BOSS提示器";
        case 49:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [12:10] 来自神油BOSS提示器";
        case 50:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [12:30] 来自神油BOSS提示器";
        case 51:
            return u8"";
        case 52:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [13:00] 来自神油BOSS提示器";
        case 53:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [13:00] 来自神油BOSS提示器";
        case 54:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [13:30] 来自神油BOSS提示器";
        case 55:
            return u8"";
        case 56:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [14:05] 来自神油BOSS提示器";
        case 57:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [14:10] 来自神油BOSS提示器";
        case 58:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [14:30] 来自神油BOSS提示器";
        case 59:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [14:30] 来自神油BOSS提示器";
        case 60:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [15:00] 来自神油BOSS提示器";
        case 61:
            return u8"";
        case 62:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [15:30] 来自神油BOSS提示器";
        case 63:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [16:00] 来自神油BOSS提示器";
        case 64:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [16:05] 来自神油BOSS提示器";
        case 65:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [16:10] 来自神油BOSS提示器";
        case 66:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [16:30] 来自神油BOSS提示器";
        case 67:
            return u8"";
        case 68:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [17:00] 来自神油BOSS提示器";
        case 69:
            return u8"";
        case 70:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [17:30] 来自神油BOSS提示器";
        case 71:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [17:30] 来自神油BOSS提示器";
        case 72:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [18:05] 来自神油BOSS提示器";
        case 73:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [18:10] 来自神油BOSS提示器";
        case 74:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [18:30] 来自神油BOSS提示器";
        case 75:
            return u8"";
        case 76:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [19:00] 来自神油BOSS提示器";
        case 77:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [19:00] 来自神油BOSS提示器";
        case 78:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [19:30] 来自神油BOSS提示器";
        case 79:
            return u8"";
        case 80:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [20:05] 来自神油BOSS提示器";
        case 81:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [20:10] 来自神油BOSS提示器";
        case 82:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [20:30] 来自神油BOSS提示器";
        case 83:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [20:30] 来自神油BOSS提示器";
        case 84:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [21:00] 来自神油BOSS提示器";
        case 85:
            return u8"";
        case 86:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [21:30] 来自神油BOSS提示器";
        case 87:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [22:00] 来自神油BOSS提示器";
        case 88:
            return u8"大型事件提醒 <<赌场闪电战>> [&BLsKAAA=] [22:05] 来自神油BOSS提示器";
        case 89:
            return u8"大型事件提醒 <<苍翠龙母>> [&BAgIAAA=]  [22:10] 来自神油BOSS提示器";
        case 90:
            return u8"大型事件提醒 <<缠藤虫王>>  [&BPUHAAA=] [22:30] 来自神油BOSS提示器";
        case 91:
            return u8"";
        case 92:
            return u8"大型事件提醒 <<赤金四门>>  [&BGwIAAA=] [23:00] 来自神油BOSS提示器";
        case 93:
            return u8"";
        case 94:
            return u8"大型事件提醒 <<巨龙阵地>> [&BBAIAAA=] [23:30] 来自神油BOSS提示器";
        case 95:
            return u8"大型事件提醒 <<巨蛇之怒>> [&BHQKAAA=] [23:30] 来自神油BOSS提示器";
        default:
            return u8"未知错误";
        }

    }
    return u8"未知错误";
}
enum class bossname
{
    碎裂巨兽,
    冰萨满,
    人马王,
    火元素,
    魔像,
    林地虫,
    卓玛,
    暗影巨兽,
    科文顿,
    超能毁灭,//9
    僵尸龙,
    跑男1,
    当前事件1,
    三重麻烦,
    当前事件2,
    帕拉瓦,
    跑男2,
    当前事件3,
    喀壳虫女王,
    当前事件4,
    跑男3,
    当前事件5,
    当前事件6,
    空,//23
    赌场闪电战,
    龙母,
    虫王,
    四门,
    巨蛇,
    巨龙,

};
const char* GetBossName(bossname m)
{
    switch (m)
    {
    case bossname::碎裂巨兽:
        return u8"碎裂巨兽";
    case bossname::冰萨满:
        return u8"冰萨满";
    case bossname::人马王:
        return u8"人马王";
    case bossname::火元素:
        return u8"火元素";
    case bossname::魔像:
        return u8"马克魔像";
    case bossname::林地虫:
        return u8"林地虫";
    case bossname::卓玛:
        return u8"冰龙卓玛";
    case bossname::暗影巨兽:
        return u8"暗影巨兽";
    case bossname::科文顿:
        return u8"科文顿海盗";
    case bossname::超能毁灭:
        return u8"超能毁灭";
    case bossname::僵尸龙:
        return u8"僵尸龙";
    case bossname::跑男1:
        return u8"甘达拉战区跑男";
    case bossname::当前事件1:
        return u8"当前事件1";
    case bossname::三重麻烦:
        return u8"三重麻烦";
    case bossname::当前事件2:
        return u8"当前事件2";
    case bossname::帕拉瓦:
        return u8"伊斯坦帕拉瓦";
    case bossname::跑男2:
        return u8"林线瀑布跑男";
    case bossname::当前事件3:
        return u8"当前事件3";
    case bossname::喀壳虫女王:
        return u8"喀壳虫女王";
    case bossname::当前事件4:
        return u8"当前事件4";
    case bossname::跑男3:
        return u8"钢铁平原跑男";
    case bossname::当前事件5:
        return u8"当前事件5";
    case bossname::当前事件6:
        return u8"当前事件6";
    case bossname::赌场闪电战:
        return u8"赌场闪电战";
    case bossname::龙母:
        return u8"苍翠龙母";
    case bossname::虫王:
        return u8"缠藤虫王";
    case bossname::四门:
        return u8"赤金四门";
    case bossname::巨蛇:
        return u8"瓦比巨蛇";
    case bossname::巨龙:
        return u8"巨龙阵地";
    case bossname::空:
        return u8"";
    default:
        return u8"[未知]";
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
        //ImGui::Begin(u8"BOSS计时器_by印度神油", &setting, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
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
            if (ImGui::SmallButton(u8"关 闭")) setting = false; ImGui::SameLine();
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
