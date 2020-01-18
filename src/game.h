//
//game settings
//

namespace RPGMMO_game{
    class Game{
        public:
        struct Base_character_properties
        {
            int STR,//力量（微量增加生命值，近战伤害）
                CON,//体质（增加生命值，负重）
                SIZ,//体型
                DEX,//敏捷（增加命中率，微量减少受到的物理损伤）
                APP,//外貌
                PER,//智力，灵感
                POW,//意志（影响生命值，法力，精力上限）
                EDU,//教育
                MOV;//移动力     
        };

        struct Secondary_character_properties
        {
            int ATT,//攻击力 
                ATN,//物理攻击力
                INT,//魔法攻击力
                DEF,//防御力
                RES,//魔法防御力
                SPD,//速度，回避物理攻击
                HIT,//命中率或者连击
                MAG,//魔力（影响法力上限）
                CHR,//魅力（影响NPC如何对待角色，同时也影响商店道具的售价、表演收入、能有多少宠物）
                SPEED,//决定角色经过多久之后是一回合，同时也影响在世界地图上的移动力
                LIFE;//角色每级HP的成长率
        };

        
        
    };
        
           
            
        
    
}