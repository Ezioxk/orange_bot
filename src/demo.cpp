#include <iostream>
#include <set>
#include <sstream>

#include "cqcppsdk.h"

using namespace cq;
using namespace std;

CQ_INIT {
    on_enable([] { logging::info("启用", "插件已启用"); });

    on_private_message([](const PrivateMessageEvent &e) {
        try {
            auto msgid = send_private_message(e.user_id, e.message); // 直接复读消息
            logging::info_success("私聊", "私聊消息复读完成, 消息 Id: " + to_string(msgid));
        } catch (ApiError &e) {
            logging::warning("私聊", "私聊消息复读失败, 错误码: " + e.code);
        }
    });

    on_group_message([](const GroupMessageEvent &e) {
        static const set<int64_t> ENABLED_GROUPS = {539398012,87210195};
        if (ENABLED_GROUPS.count(e.group_id) == 0) return; // 不在启用的群中, 忽略
        
        // try {
        //     send_message(e.target, e.message); // 复读
        //     auto mem_list = get_group_member_list(e.group_id); // 获取群成员列表
        //     string msg;
        //     for (auto i = 0; i < min(10, static_cast<int>(mem_list.size())); i++) {
        //         msg += "昵称: " + mem_list[i].nickname + "\n"; // 拼接前十个成员的昵称
        //     }
        //     send_group_message(e.group_id, msg); // 发送群消息
        // } catch (ApiError &) { // 忽略发送失败
        // }
        if (e.is_anonymous()) {
            logging::info("群聊", "消息是匿名消息, 匿名昵称: " + e.anonymous.name);
        }
        e.block(); // 阻止当前事件传递到下一个插件
    });

    on_group_upload([](const auto &e) { // 可以使用 auto 自动推断类型
        stringstream ss;
        ss << "您上传了一个文件, 文件名: " << e.file.name << ", 大小(字节): " << e.file.size;
        try {
            send_message(e.target, ss.str());
        } catch (ApiError &) {
        }
    });

    on_group_ban([](const GroupBanEvent &e) {
    // 事件处理逻辑
        logging::info("测试","subtype="+e.sub_type);

            User victim = get_stranger_info(e.user_id);
            User oprator = get_stranger_info(e.operator_id);
            
            if (e.sub_type == GroupBanEvent::SubType::BAN  ){
                     
                    try {
                    send_group_message(e.group_id , victim.nickname + "被"+ oprator.nickname + "禁言了");
                }catch (ApiError &e) {
                        logging::warning("禁言消息", "禁言消息发送失败, 错误码: " + e.code);
                }

            }else
                return;
            
    

    });

    // on_friend_request([](const FriendRequestEvent &e){
    //     set_friend_request(e.flag,FriendRequestEvent::Operation::APPROVE,e.flag);

    // });

}
    

CQ_MENU(menu_demo_1) { logging::info("菜单", "点击菜单1"); }

CQ_MENU(menu_demo_2) { send_private_message(452929533, "测试"); }
