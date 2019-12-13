//
//  ECConferenceManager.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/2/13.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
#endif
#import "ECError.h"
#import "ECManagerBase.h"
#import "ECConferenceInfo.h"
#import "ECConferenceCondition.h"
#import "ECConferenceMemberInfo.h"
#import "ECConferenceJoinInfo.h"
#import "ECConferenceVideoInfo.h"
#import "ECConferenceAppSettingInfo.h"
#import "ECConferenceAbstract.h"
#import "ECConferenceLiveInfo.h"
#import "ECRecordInfo.h"
#import "ECEntityConferenceInfo.h"
#import "ECConferenceSummary.h"

typedef NS_ENUM(NSInteger,ECControlMediaAction) {
    /** 多状态变更 */
    ECControlMediaAction_moreChanged  = -1,
    
    /** 禁听 */
    ECControlMediaAction_CloseListen = 0,
    
    /** 可听 */
    ECControlMediaAction_OpenListen = 1,
    
    /** 禁言 */
    ECControlMediaAction_CloseSpeak = 2,
    
    /** 可说 */
    ECControlMediaAction_OpenSpeak = 3,
    
    /** 停止观看视频 */
    ECControlMediaAction_CloseLookVideo = 10,
    
    /** 观看视频 */
    ECControlMediaAction_OpenLookVideo = 11,
    
    /** 停止发布视频 */
    ECControlMediaAction_StopPublish = 12,
    
    /** 发布视频 */
    ECControlMediaAction_PublishVideo = 13,
    
    /** 停止观看屏幕共享 */
    ECControlMediaAction_CloseLookScreen =20,
    
    /** 观看屏幕共享 */
    ECControlMediaAction_OpenLookScreen = 21,
    
    /** 关闭共享 */
    ECControlMediaAction_CloseScreen = 22,
    
    /** 打开共享 */
    ECControlMediaAction_OpenScreen = 23,
    
    /** 关闭成员的白板共享收看 */
    ECControlMediaAction_StopLookBoard   = 30,
    
    /** 打开议成员的白板共享收看 */
    ECControlMediaAction_OpenLookBoard   = 31,
    
    /** 停止议成员的白板共享 */
    ECControlMediaAction_StopShareBoard  = 32,
    
    /** 开始议成员的白板共享 */
    ECControlMediaAction_OpenShareBoard  = 33,
    
    /** 禁止成员操作白板 */
    ECControlMediaAction_ForbidOperBoard = 34,
    
    /** 允许成员操作白板 */
    ECControlMediaAction_AllowOperBoard  = 35,
    
    /** 主持人变更 */
    ECControlMediaAction_HostChanged  = 50,
    
    /** 成员名字变更 */
    ECControlMediaAction_nameChanged  = 51,
    
    /** 会议摘要变化 */
    ECControlMediaAction_AbstractChanged = 76,
    
    /*主持人点名成员成为发言人*/
    ECControlApplyPublishVoiceByModerator = 77,
    
    /*主持人同意成员成为发言人*/
    ECControlAcceptPublishVoiceByModerator = 78,
    
    /*主持人拒绝成员的举手发言*/
    ECControlRejectPublishVoiceByModerator = 79,
    
    /** 主持人 取消发言人权限，即更改发言人角色为 普通成员 */
    ECControlStopPublishVoiceByModerator = 80,
    
    /** 参会人 申请发言 */
    ECControlApplyPublishVoiceBySelf = 81,
    
    /** 参会人 同意点名 */
    ECControlAcceptPublishVoiceBySelf = 82,
    
    /** 参会人 拒绝点名 */
    ECControlRejectPublishVoiceBySelf = 83,
    
    /**参会人 取消发言*/
    ECControlStopPublishVoiceBySelf = 84,
};

typedef NS_ENUM(NSUInteger,ECRecordAction) {
    
    /** 开始录音语音 */
    ECRecordAction_RecordSound = 0,
    
    /** 停止录音语音 */
    ECRecordAction_StopSound = 1,
    
    /** 开始录制摄像头视频 */
    ECControlMediaAction_RecordCameraVideo = 10,
    
    /** 停止录制摄像头视频 */
    ECControlMediaAction_StopCameraVideo = 11,
    
    /** 开始录制共享屏幕 */
    ECControlMediaAction_RecordScreenVideo =20,
    
    /** 停止录制共享屏幕 */
    ECControlMediaAction_StopScreenVideo = 21,
    
    /** 开始录制白板 */
    ECControlMediaAction_StartRecordBoard = 30,
    
    /** 停止录制白板 */
    ECControlMediaAction_StopRecordBoard = 31,
    
    /** 开始录制所有 */
    ECControlMediaAction_StartRecordAll = 40,
    
    /** 停止录制所有 */
    ECControlMediaAction_StopRecordAll = 41,
    
};

typedef NS_ENUM(NSUInteger,ECPlayAction) {
    
    /** 开始放音 */
    ECPlayAction_PlayAudio = 0,
    
    /** 停止放音 */
    ECPlayAction_StopAudio = 1,
};

/**
 * 会议管理类_V2
 * 用于创建、解散、会议成员管理等
 */
@protocol ECConferenceManager <ECManagerBase>


/**
 @brief 获取应用下的总的会议设置信息
 @param completion 执行结果回调block
 */
- (void)getConferenceAppSetting:(void(^)(ECError* error, ECConferenceAppSettingInfo *appSettingfo))completion;

/**
 @brief 获取用户会议室ID
 @param completion 执行结果回调block
 */
- (void)getConfroomIdListWithAccount:(ECAccountInfo *)member confId:(NSString *)confId completion:(void(^)(ECError* error, NSArray *arr))completion;

/**
 @brief 创建会议
 @param conferenceInfo 会议类
 @param completion 执行结果回调block
 */
- (void)createConference:(ECConferenceInfo*)conferenceInfo completion:(void(^)(ECError* error, ECConferenceInfo*conferenceInfo))completion;

/**
 @brief 删除会议
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)deleteConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 更新会议信息
 @param conferenceInfo 会议类
 @param completion 执行结果回调block
 */
- (void)updateConference:(ECConferenceInfo*)conferenceInfo completion:(void(^)(ECError* error))completion;

/**
 @brief 更新历史会议信息
 @param conferenceInfo 会议类
 @param completion 执行结果回调block
 */
- (void)updateHistoryConference:(ECConferenceInfo*)conferenceInfo completion:(void(^)(ECError* error))completion;

/**
 @brief 更新历史会议信息
 @param conferenceInfo 会议类
 @param appData app自定义信息
 @param completion 执行结果回调block
 */
- (void)updateHistoryConference:(ECConferenceInfo*)conferenceInfo withAppData:(NSString *)appData completion:(void(^)(ECError* error))completion;

/**
 @brief 获取摘要列表
 @param conferenceId 会议id
 @param isHistoryConf 是否历史会议
 @param CGPage 分页
 @param completion 执行结果回调block
 */
- (void)getConferenceAbstractList:(NSString*)conferenceId historyConf:(BOOL)isHistoryConf page:(CGPage)page completion:(void(^)(ECError* error, NSArray* abstractList))completion;

/**
 @brief 更新摘要信息
 @param conferenceId 会议id
 @param isHistoryConf 是否历史会议
 @param ECConferenceAbstract 摘要内容（摘要ID传空时为创建新的摘要）
 @param completion 执行结果回调block
 */
- (void)updateConferenceAbstract:(NSString*)conferenceId historyConf:(BOOL)isHistoryConf abstract:(ECConferenceAbstract*)abstract completion:(void(^)(ECError* error, ECConferenceAbstract* abstract))completion;

/**
 @brief 删除摘要
 @param conferenceId 会议id
 @param isHistoryConf 是否历史会议
 @param abstractIds 摘要ID
 @param completion 执行结果回调block
 */
- (void)deleteConferenceAbstract:(NSString*)conferenceId historyConf:(BOOL)isHistoryConf abstractIds:(NSArray*)abstractIds completion:(void(^)(ECError* error))completion;

/**
 @brief 发送透传信息
 @param cmdData 透传字段
 @param members ECAccountInfo数组 控制成员列表
 @param isAllMember 是否全部成员
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)conferenceSendCmd:(NSString *)cmdData toMembers:(NSArray*)members isAll:(int)isAllMember ofConference:(NSString*)confId completion:(void(^)(ECError* error))completion;


/**
 @brief 获取会议信息
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)getConference:(NSString*)confId completion:(void(^)(ECError* error, ECConferenceInfo*conferenceInfo))completion;

/**
 @brief 获取会议列表
 @param condition 筛选条件
 @param page 分页信息
 @param completion 执行结果回调block
 */
- (void)getConferenceListWithCondition:(ECConferenceCondition*)condition page:(CGPage)page ofMember:(ECAccountInfo*)member completion:(void(^)(ECError* error, NSArray* conferenceList))completion;

/**
 @brief 获取会议列表
 @param condition 筛选条件
 @param confRoomId 会议室id
 @param page 分页信息
 @param completion 执行结果回调block
 */
- (void)getConferenceListWithCondition:(ECConferenceCondition*)condition confRoomId:(NSString *)confRoomId page:(CGPage)page ofMember:(ECAccountInfo*)member completion:(void(^)(ECError* error, NSArray* conferenceList))completion;

/**
 @brief 获取历史会议列表
 @param condition 筛选条件
 @param page 分页信息
 @param completion 执行结果回调block
 */
- (void)getHistoryConferenceListWithCondition:(ECConferenceCondition*)condition page:(CGPage)page completion:(void(^)(ECError* error, NSArray* conferenceList))completion;

/**
 @brief 获取历史会议列表
 @param condition 筛选条件
 @param confRoomId 会议室id
 @param page 分页信息
 @param completion 执行结果回调block
 */
- (void)getHistoryConferenceListWithCondition:(ECConferenceCondition*)condition confRoomId:(NSString *)confRoomId page:(CGPage)page completion:(void(^)(ECError* error, NSArray* conferenceList))completion;

/**
 @brief 锁定会议
 @param confId 会议ID
 @param lockType 0 锁定，1 解锁，2 锁定白板发起，3 解锁，4 锁定白板标注，5 解锁
 @param completion 执行结果回调block
 */
- (void)lockConference:(NSString*)confId lockType:(int)lockType completion:(void(^)(ECError* error))completion;

/**
 @brief 加入会议
 @param joinInfo 加入条件
 @param completion 执行结果回调block
 */
- (void)joinConferenceWith:(ECConferenceJoinInfo*)joinInfo completion:(void(^)(ECError* error, ECConferenceInfo*conferenceInfo))completion;

/**
 @brief 退出会议
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)quitConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 更换成员信息
 @param memberInfo 成员信息
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)updateMember:(ECConferenceMemberInfo*)memberInfo ofConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 获取成员信息
 @param member 账号信息
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)getMember:(ECAccountInfo*)member ofConference:(NSString*)confId completion:(void(^)(ECError* error, ECConferenceMemberInfo* memberInfo))completion;

/**
 @brief 获取成员列表
 @param confId 会议ID
 @param page 分页信息
 @param completion 执行结果回调block
 */
- (void)getMemberListOfConference:(NSString*)confId page:(CGPage)page completion:(void(^)(ECError* error, NSArray* members))completion;

/**
 @brief 获取会议中的成员与会记录
 @param accountInfo 相关成员记录 如果为nil，获取所有成员与会记录
 @param confId 会议ID
 @param page 分页信息
 @param completion 执行结果回调block
 */
- (void)getMemberRecord:(ECAccountInfo*)accountInfo ofConference:(NSString*)confId page:(CGPage)page completion:(void(^)(ECError* error, NSArray* membersRecord))completion;

/**
 @brief 获取会议中的成员与会记录
 @param accountInfo 相关成员记录 如果为nil，获取所有成员与会记录
 @param confId 会议ID
 @param page 分页信息
 @param duplicate 返回的数据是否包含重复成员 0:返回去除的结果，每个成员仅返回一条记录 1:返回所有成员，同一成员可能入会多次，结果包含重复
 @param completion 执行结果回调block
 */
- (void)getMemberRecord:(ECAccountInfo*)accountInfo ofConference:(NSString*)confId page:(CGPage)page duplicate:(int)duplicate completion:(void(^)(ECError* error, NSArray* membersRecord))completion;

/**
 @brief 邀请加入会议
 @param inviteMembers ECAccountInfo数组 邀请的成员
 @param confId 会议ID
 @param callImmediately 是否立即发起呼叫 对于自定义账号，1表示给用户显示呼叫页面，并设置超时时间1分钟 对于电话号码（或关联电话）账号，1表示立即给cm发呼叫命令 0表示仅在会议中增加成员（一般用户预约会议开始前增加成员）
 @param appData 预留
 @param completion 执行结果回调block
 */
- (void)inviteMembers:(NSArray*)inviteMembers inConference:(NSString*)confId callImmediately:(int)callImmediately appData:(NSString*)appData completion:(void(^)(ECError* error))completion;

/**
 @brief 拒绝会议邀请
 @param invitationId 邀请的id
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)rejectInvitation:(NSString*)invitationId cause:(NSString*)cause ofConference:(NSString*)confId completion:(void(^)(ECError* error))completion;
/**
 @brief 踢出成员
 @param kickMembers ECAccountInfo数组 踢出的成员
 @param confId 会议ID
 @param appData 预留
 @param completion 执行结果回调block
 */
- (void)kickMembers:(NSArray*)kickMembers outConference:(NSString*)confId appData:(NSString*)appData completion:(void(^)(ECError* error))completion;

/**
 @brief 设置成员角色
 @param member 相关设置信息
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)setMemberRole:(ECAccountInfo*)member ofConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 媒体控制
 @param action 控制动作
 @param members ECAccountInfo数组 控制成员列表
 @param isAllMember 是否全部成员
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)controlMedia:(ECControlMediaAction)action toMembers:(NSArray*)members isAll:(int)isAllMember ofConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 媒体控制

 @param action 控制动作
 @param changeable 是否不可被目标成员更改，0：否，1：是
 @param members 数组 控制成员列表， id
 @param isAllMember 是否全部成员
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)controlMedia:(ECControlMediaAction)action isChangable:(int)changeable toMembers:(NSArray*)members isAll:(int)isAllMember ofConference:(NSString*)confId  completion:(void(^)(ECError* error))completion;

/**
 @brief 会议媒体是否sdk自动控制   1 sdk收到会控通知会自动控制媒体 0 sdk不会控制媒体相关

 @param isAuto 是否自动控制
 */
- (NSInteger)setConferenceAutoMediaControl:(BOOL)isAuto;

/**
 @brief 会议录制
 @param action 录制控制
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)record:(ECRecordAction)action conference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 发布音频
 @param confId 会议ID
 @param exclusively 仅用于实时对讲功能。
 1 表示控麦，此时仅允许会中有一个人发布语音，如果已经有人发布语音，此接口调用会返回错误
 0 表示发布语音，不考虑其他人语音发布状态
 @param completion 执行结果回调block
 */
- (void)publishVoiceInConference:(NSString*)confId exclusively:(int)exclusively completion:(void(^)(ECError* error))completion;

/**
 @brief 取消发布
 @param confId 会议ID
 @param exclusively 仅用于实时对讲功能。
 1 表示控麦，此时仅允许会中有一个人发布语音，如果已经有人发布语音，此接口调用会返回错误
 0 表示发布语音，不考虑其他人语音发布状态
 @param completion 执行结果回调block
 */
- (void)stopVoiceInConference:(NSString*)confId exclusively:(int)exclusively completion:(void(^)(ECError* error))completion;

/**
 @brief 发布视频
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)publishVideoInConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 取消发布
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)cancelVideoInConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 共享屏幕
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)shareScreenInConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 停止共享屏幕
 @param confId 会议ID
 @param completion 执行结果回调block
 */
- (void)stopScreenInConference:(NSString*)confId completion:(void(^)(ECError* error))completion;

/**
 @brief 发布共享
 @param confId 会议ID
 @param shareInfo 共享的信息
 @param completion 执行结果回调block
 */
- (void)startWhiteboardSharing:(NSString*)confId shareInfo:(NSString *)shareInfo completion:(void(^)(ECError* error))completion;

/**
 @brief 停止共享
 @param confId 会议ID
 @param shareInfo 共享的信息
 @param completion 执行结果回调block
 */
- (void)stopWhiteboardSharing:(NSString*)confId shareInfo:(NSString *)shareInfo completion:(void(^)(ECError* error))completion;

/**
 @brief 请求成员视频
 @param videoInfo 视频信息
 @param completion 执行结果回调block
 */
- (void)requestMemberVideoWith:(ECConferenceVideoInfo*)videoInfo completion:(void(^)(ECError* error))completion;

/**
 @brief 停止成员视频
 @param videoInfo 视频信息
 @param completion 执行结果回调block
 */
- (void)stopMemberVideoWith:(ECConferenceVideoInfo*)videoInfo completion:(void(^)(ECError* error))completion;

/**
 @brief 重置显示View
 @param videoInfo 视频信息
 */
- (int)resetMemberVideoWith:(ECConferenceVideoInfo*)videoInfo;

/**
 @brief 重置本地预览显示View
 */
#if TARGET_OS_IPHONE
- (int)resetLocalVideoWithConfId:(NSString *)confId remoteView:(UIView *)remoteView localView:(UIView *)localView;
#elif TARGET_OS_MAC
- (int)resetLocalVideoWithConfId:(NSString *)confId remoteView:(NSView *)remoteView localView:(NSView *)localView;
#endif

/**
 @brief 获取通话中的视频统计报告
 reportsJsonOut:  统计数据
 {
 "VideoSenderStatistics":[{"channelId":(通道id,uint32),"codecName":"(编码名称，string)","transmitBitrate":(码率，uint32),"width":(宽，uint32),"height":"(高，uint32)","frameRate":(帧率，uint32),"lossPercent":"(丢包率，单位%，uint32)","rttMs":(时延，单位毫秒，uint32)}]，
 "VideoReceiverStatistics":[{"channelId":(通道id,uint32),"codecName":"(编码名称，string)","transmitBitrate":(码率，uint32),"width":(宽，uint32),"height":"(高，uint32)","frameRate":(帧率，uint32)}]
 }
 */
- (int)getStatsReportsCompletion:(void(^)(NSString* reportsJsonOut))completion;

/**
 @brief 发送DTMF
 @param confID 会议id
 @param dtmf 键值
 @return 0:成功  非0:失败
 */
- (NSInteger)sendDTMFWithConfID:(NSString *)confID dtmf:(NSString *)dtmf;

#pragma mark -- 5.4.3.4

/**
 @brief 网络抓包

 @param confId 会议id
 @param memberId 成员id
 @param mediaType 媒体类型 （ECMediaType_Video 视频、ECMediaType_Share 共享）
 @param fileName 抓包写入的文件路径
 @return 是否成功 0：成功； 非0失败
 */
- (int)conferenceStartMemberRtpDump:(NSString *)confId member:(NSString *)memberId mediaType:(ECMediaType)mediaType fileName:(NSString *)fileName;


/**
 @brief 停止抓包

 @param confId 会议id
 @param memberId 成员id
 @param mediaType 媒体类型
 @return 是否成功 0：成功； 非0失败
 */
- (int)conferenceStopMemberRtpDump:(NSString *)confId member:(NSString *)memberId   mediaType:(ECMediaType)mediaType;

/**
 @brief 设置声音最大最小参会成员显示的时间间隔

 @param timeInterVal 时间间隔
 @return 设置是否成功
 */
- (int)conferenceParticipantCallbackTimeInterVal:(NSInteger)timeInterVal;

#pragma mark === 5.4.4.4

/**
 @brief 开始会议直播

 @param conference 直播会议id
 @param userId 用户id
 @param record 是否录像
 @param isAuto 混屏切换模式，YES 自动， NO 手动
 @param completion 完成回调
 @return 请求发送成功/失败
 */
- (int)conferenceStartLive:(ECConferenceStartLiveRequest *)requestInfo completion:(void(^)(ECError* error, ECConferenceLiveUrlInfo *liveUrl))completion;

/**
 @brief 停止会议直播

 @param conferenceId 直播会议id
 @param userId 用户id
 @param completion 完成回调
 @return 请求发送成功/失败
 */
- (int)conferenceStopLive:(NSString *)conferenceId completion:(void(^)(ECError* error))completion;

/**
 @brief 获取会议直播url

 @param conferenceId 会议id
 @param userId 用户id
 @param completion 完成回调
 @return 请求发送成功/失败
 */
- (int)conferenceGetPlayUrl:(NSString *)conferenceId completion:(void(^)(ECError* error, ECConferenceLiveUrlInfo *liveUrl))completion;

/**
 @brief 会议成员直播切换

 @param conferenceId 会议id
 @param userId 用户id
 @param members 会议成员(ECAccount)信息数组，accountId、accountType必选
 @param completion 完成回调
 @return 请求发送结果
 */
- (int)conferenceSwitchMember:(NSString *)conferenceId members:(NSArray *)members   completion:(void(^)(ECError* error))completion;

#pragma mark === 5.4.6

/**
 @brief 设置呼叫类型

 @param confCallType 类型， 设置会议呼叫类型，比如采用思科双流还是POLYCOM双流呼叫,目前传递6或者是7，其他暂时不支持
 @return 设置回调
 */
- (int)setConferenceCallType:(int)confCallType;

#pragma mark ==== 5.4.10

/**
 获取会议录制文件列表

 @param confId 会议ID
 @param isHistory 指明当前会议类型 0:当前会议 1:历史会议
 @param page 分页
 @param completion 完成回调, ECRecordInfo 数组
 */
- (void)conferenceRecordList:(NSString *)confId isHistory:(int)isHistory page:(CGPage)page completion:(void(^)(ECError* error, NSArray *recordLisr))completion;

/**
 获取会议纪要列表

 @param confId 会议id
 @param page 分页
 @param completion 完成回调， ECConferenceSummary数组
 */
- (void)conferenceSummaryList:(NSString *)confId page:(CGPage)page completion:(void(^)(ECError* error, NSArray *summaryLisr))completion;


/**
 延长会议时间
 add by lxj

 @param confId (必选)会议ID
 @param tryMinDuration 可选 延长的最少时间，单位：分钟 如果无法延长到该最少时间，更新失败
 @param tryMaxDuration 可选 延长的最大时间，单位：分钟 如果能满足延长至该最大时间，会议将延长该最大时间。如果不能满足延长该值，服务器延长至可延长的最大时间
 @param completion 完成回调
 */
- (void)extendDurationInConference:(NSString *)confId tryMinDuration:(int)tryMinDuration tryMaxDuration:(int)tryMaxDuration completion:(void(^)(ECError* error))completion;


/**
 会议通用接口

 @param path 接口路径
 @param jsonString json字符串
 @param completion 回调
 */
- (void)commonConferenceByPath:(NSString *)path jsonString:(NSString *)jsonString completion:(void(^)(ECError *error,NSString *jsonString))completion;
    
@end

