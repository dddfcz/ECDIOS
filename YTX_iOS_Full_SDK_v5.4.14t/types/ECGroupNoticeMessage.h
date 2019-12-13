/**
 @header ECGroupNoticeMessage.h
 @abstract 群组通知回调事件的类说明
 */

#import <Foundation/Foundation.h>
#import "ECBaseNoticeMsg.h"

/**
 * 群组通知消息类型枚举
 */
typedef NS_ENUM(NSUInteger, ECGroupMessageType) {
    
    /** 群组解散 */
    ECGroupMessageType_Dissmiss,
    
    /** 邀请加入 */
    ECGroupMessageType_Invite,
    
    /** 申请加入 */
    ECGroupMessageType_Propose,
    
    /** 加入群组 */
    ECGroupMessageType_Join,
    
    /** 退出群组 */
    ECGroupMessageType_Quit,
    
    /** 踢出成员 */
    ECGroupMessageType_RemoveMember,
    
    /** 验证邀请 */
    ECGroupMessageType_ReplyInvite,
    
    /** 验证加入 */
    ECGroupMessageType_ReplyJoin,
    
    /** 群组信息修改 */
    ECGroupMessageType_ModifyGroup,
    
    /** 管理员更改 */
    ECGroupMessageType_ChangeAdmin,
    
    /** 角色更改 */
    ECGroupMessageType_ChangeMemberRole,
    
    /** 群组成员信息修改 */
    ECGroupMessageType_ModifyGroupMember,
    
    /** 邀请加入(无需验证方式) */
    ECGroupMessageType_InviteJoin,
    
    /**管理员批量审核成员加入的通知**/
    ECGroupMessageType_VerifyJoin,
    
    /**群组成员邀请加入，发给管理员审核通知**/
    ECGroupMessageType_InviteMultiple
    
};


#pragma mark - 群组通知消息基类
/**
 * 群组通知消息基类
 */
@interface ECGroupNoticeMessage : ECBaseNoticeMsg

/**
 @brief 通知消息发送账号
 */
@property (nonatomic, copy) NSString *sender;

/**
 @brief 群组ID
 */
@property (nonatomic, copy) NSString *groupId;

/**
 @brief 群组名
 */
@property (nonatomic, copy) NSString *groupName;

/**
 @brief 群组类型
 */
@property (nonatomic, readonly) ECGroupMessageType messageType;

/**
 @brief 是否讨论组/群组 1 讨论组 2 群组
 */
@property (nonatomic, assign) BOOL isDiscuss;
@end


#pragma mark - 解散群组
/**
 * 解散群组
 */
@interface ECDismissGroupMsg : ECGroupNoticeMessage

/**
 @brief 管理员
 */
@property (nonatomic, copy) NSString *admin;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

@end


#pragma mark - 收到邀请
/**
 * 收到邀请
 */
@interface ECInviterMsg : ECGroupNoticeMessage

/**
 @brief 管理员
 */
@property (nonatomic, copy) NSString *admin;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief 邀请理由
 */
@property (nonatomic, copy) NSString *declared;

/**
 @brief 是否需要验证 0不需要确认 1需要确认
 */
@property (nonatomic, assign) NSInteger confirm;
@end

#pragma mark - 收到申请
/**
 * 收到申请
 */
@interface ECProposerMsg : ECGroupNoticeMessage

/**
 @brief 申请者id
 */
@property (nonatomic, copy) NSString *proposer;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief 申请理由
 */
@property (nonatomic, copy) NSString *declared;

/**
 @brief 是否需要验证 0不需要确认 1需要确认
 */
@property (nonatomic, assign) NSInteger confirm;
@end

#pragma mark - 管理员更改
/**
 * 管理员更改
 */
@interface ECChangeAdminMsg : ECGroupNoticeMessage

/**
 @brief 管理员账号
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 管理员昵称
 */
@property (nonatomic, copy) NSString *nickName;

@end

#pragma mark - 有成员加入
/**
 * 有成员加入
 */
@interface ECJoinGroupMsg : ECGroupNoticeMessage

/**
 @brief 加入成员
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief
 */
@property (nonatomic, copy) NSString *declared;
@end

#pragma mark - 退出群组
/**
 * 退出群组
 */
@interface ECQuitGroupMsg : ECGroupNoticeMessage

/**
 @brief 退出的成员
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;
@end

#pragma mark - 移除成员
/**
 * 移除成员
 */
@interface ECRemoveMemberMsg : ECGroupNoticeMessage

/**
 @brief 移除的成员
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;
@end

#pragma mark - 答复申请加入
/**
 * 答复申请加入
 */
@interface ECReplyJoinGroupMsg : ECGroupNoticeMessage

/**
 @brief 管理员
 */
@property (nonatomic, copy) NSString *admin;

/**
 @brief 是否需要验证 1拒绝 2同意
 */
@property (nonatomic, assign) NSInteger confirm;

/**
 @brief 加入的成员
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;
@end

#pragma mark - 答复邀请加入
/**
 * 答复邀请加入
 */
@interface ECReplyInviteGroupMsg : ECGroupNoticeMessage

/**
 @brief 管理员
 */
@property (nonatomic, copy) NSString *admin;

/**
 @brief 管理员昵称
 */
@property (nonatomic, copy) NSString *adminNickName;

/**
 @brief 是否需要验证 1拒绝 2同意
 */
@property (nonatomic, assign) NSInteger confirm;

/**
 @brief 加入的成员
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief 拥有的版本
 */
@property (nonatomic, assign) NSInteger hasVersion;

@end

#pragma mark - 邀请加入
/**
 * 邀请加入
 */
@interface ECInviteJoinGroupMsg : ECGroupNoticeMessage

/**
 @brief 管理员
 */
@property (nonatomic, copy) NSString *admin;

/**
 @brief 管理员昵称
 */
@property (nonatomic, copy) NSString *adminNickName;

/**
 @brief 加入的成员
 */
@property (nonatomic, copy) NSArray *members;

@end

#pragma mark - 群组信息修改
/**
 * 群组信息修改
 */
@interface ECModifyGroupMsg : ECGroupNoticeMessage

/**
 @brief 修改者
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief 群组修改的信息
 */
@property (nonatomic, copy) NSDictionary *modifyDic;
@end

#pragma mark - 群组成员信息修改
/**
 * 群组成员信息修改
 */
@interface ECModifyGroupMemberMsg : ECGroupNoticeMessage

/**
 @brief 修改者
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief 成员修改的信息
 */
@property (nonatomic, copy) NSDictionary *modifyDic;
@end

#pragma mark - 角色信息修改
/**
 * 修改成员角色信息
 */
@interface ECChangeMemberRoleMsg : ECGroupNoticeMessage

/**
 @brief 修改的成员voip号
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief 角色 2管理者 3成员
 */
@property (nonatomic, copy) NSDictionary *roleDic;
@end

/**
 管理员批量审核成员加入非公开群组，合并通知给成员
 */
@interface ECVerifyJoinMembers : ECGroupNoticeMessage

/**
 @brief 公告
 */
@property (nonatomic, copy) NSString *declared;

/**
 @brief 群组变更账号
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 操作者账号
 */
@property (nonatomic, copy) NSString *admin;

/**
 @brief 角色变更昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief 是否验证加入 1是不需要验证，非1都是需要验证
 */
@property (nonatomic, assign) int confirm;

/**
 @brief 修改后的角色
 */
@property (nonatomic, copy) NSString *ext;

/**
 @brief 1 讨论组  2普通群组
 */
@property (nonatomic, copy) NSString *target;

/**
 @brief 被拉人列表
 */
@property (nonatomic, strong) NSArray *memberList;

@end

/**
 批量邀请成员加入非公开群组，合并申请通知给管理员
 */
@interface ECInviteMultipleMembers : ECGroupNoticeMessage

/**
 @brief 操作者账号
 */
@property (nonatomic, copy) NSString *admin;

/**
 @brief 消息接收者昵称
 */
@property (nonatomic, copy) NSString *adminNickName;

/**
 @brief 邀请加入群组的成员列表
 */
@property (nonatomic, strong) NSArray *memberList;

/**
 @brief 是否验证加入 1是不需要验证，非1都是需要验证
 */
@property (nonatomic, assign) int confirm;

/**
 @brief 公告
 */
@property (nonatomic, copy) NSString *declared;

/**
 @brief 修改后的角色
 */
@property (nonatomic, copy) NSString *ext;

/**
 @brief 角色变更账号
 */
@property (nonatomic, copy) NSString *member;

/**
 @brief 角色变更的昵称
 */
@property (nonatomic, copy) NSString *nickName;

/**
 @brief
 */
@property (nonatomic, copy) NSString *qrContent;

/**
 @brief 1 讨论组  2普通群组
 */
@property (nonatomic, copy) NSString *target;

@end
