//
//  ECManager.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 14/11/6.
//  Copyright (c) 2014年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECMessageManager.h"
#import "ECDeviceDelegate.h"
#import "ECLoginInfo.h"
#import "ECError.h"
#import "ECVoIPManager.h"
#import "ECMeetingManager.h"
#import "ECConferenceManager.h"
#import "ECPersonInfo.h"
#import "ECUserState.h"

#if TARGET_OS_IPHONE
#import <PushKit/PushKit.h>
#endif

#import "ECLiveStreamManager.h"

#import "ECLiveChatRoomManager.h"

#import "ECDeviceHeaders.h"
#import "ECDevicePrivate.h"

#define ECDevice_SDK_VERSION 5004013

/**
 * 设备类 使用该类的单例操作
 */
@interface ECDevice :
#if TARGET_OS_IPHONE
NSObject<UIApplicationDelegate,PKPushRegistryDelegate,ECDevicePrivate>
#else
NSObject
#endif

/**
 @brief 单例
 @discussion 获取该类单例进行操作
 @return 返回类实例
 */
+(ECDevice*)sharedInstance;

/**
 @discussion 获取SDK版本号
 @return 返回SDK版本号
 */
-(NSString*)getSDKVersion;

/**
 @brief 切换服务器环境
 @discussion 调用登录接口前，调用该接口切换服务器环境；不调用该函数，默认使用的是生产环境；
 @param isSandBox 是否沙盒环境
 @return 是否成功 0:成功 非0失败
 */
-(NSInteger)SwitchServerEvn:(BOOL)isSandBox;

/**
 @brief 登录
 @discussion 异步函数，建立与平台的连接
 @param info 登录所需信息
 @param completion 执行结果回调block
 */
-(void)login:(ECLoginInfo *)info completion:(void(^)(ECError* error)) completion;

/**
 @brief 退出登录
 @discussion 异步函数，断开与平台的连接;该函数调用后SDK不再主动重连服务器
 @param completion 执行结果回调block
 */
-(void)logout:(void(^)(ECError* error)) completion;

/**
 @brief 设置个人信息
 @param person 个人信息
 @param completion 执行结果回调block
 */
-(void)setPersonInfo:(ECPersonInfo*)person completion:(void(^)(ECError* error, ECPersonInfo* person)) completion;

/**
 @brief 获取个人信息
 @param completion 执行结果回调block
 */
-(void)getPersonInfo:(void(^)(ECError* error, ECPersonInfo* person)) completion;

/**
 @brief 获取其他人信息
 @param userAcc 用户账号
 @param completion 执行结果回调block
 */
-(void)getOtherPersonInfoWith:(NSString *)userAcc completion:(void(^)(ECError* error, ECPersonInfo* person)) completion;

/**
 @brief 设置免打扰
 @param sessionId 会话id，个人账号或群组ID
 @param isMute 是否免打扰
 @param completion 执行结果回调block
 */
-(void)setMuteNotification:(NSString*)sessionId isMute:(BOOL)isMute completion:(void(^)(ECError* error)) completion;

/**
 @brief 设置推送是否显示详情
 @param isDisplay 是否显示详情内容
 @param completion 执行结果回调block
 */
-(void)setPushDisplayDetail:(BOOL)isDisplay completion:(void(^)(ECError* error)) completion;

/**
 @brief 获取他人状态
 @param userAcc 用户账号
 @param completion 执行结果回调block
 */
-(void)getUserState:(NSString *)userAcc completion:(void(^)(ECError* error, ECUserState* state)) completion EC_DEPRECATED_IOS(5.1.8, 5.1.9, "Use - getUsersState:completion:");

/**
 @brief 获取多个他人状态
 @param userAccs 用户账号数组
 @param completion 执行结果回调block
 */
-(void)getUsersState:(NSArray *)userAccs completion:(void(^)(ECError* error, NSArray* usersState)) completion;

/**
 @brief 设置在线子状态
 @param substate 在线子状态
 @param completion 执行结果回调block
 */
-(void)setOnlineSubState:(ECPresenceType)substate completion:(void(^)(ECError* error)) completion;

/**
 @brief 获取自己在线的设备类型
 @param completion 执行结果回调block
 */
-(void)getMineOnlineMultiDevice:(void(^)(ECError* error, NSArray* multiDevices)) completion;

/**
 @brief 私有云设置
 @param companyid 公司ID
 @param companyPwd 公司密码
 */
-(void)setPrivateCloudCompanyId:(NSString*)companyid andCompanyPwd:(NSString*)companyPwd;

/**
 @brief 设置角标数
 @param badgeNumber 角标数字
 @param completion 执行结果回调block
 */
-(void)setAppleBadgeNumber:(NSInteger)badgeNumber completion:(void(^)(ECError* error)) completion;

/**
 @brief 多证书设置
 @param pushCerKey 推送证书标识，与服务器上传证书保持一致
 */
- (void)setPushCerKey:(NSString *)pushCerKey;


/**
 @brief 西安狂生电子可以需求

 @param isAuto 是否自动断开socket链接
 */
- (void)setAutoFreeSocket:(BOOL)isAuto;

/**
 @brief 设置网络代理,需要走代理时登录前设置,不支持ssl；socks5代理支持IM和点对点音视频(关闭p2p),http代理支持IM
 @param proxyHost 代理服务器地址，最大长度255。当设置空时，取消代理
 @param proxyPort 代理端口
 @param type 鉴权类型。 目前支持 0 不鉴权；2 用户名密码鉴权
 @param authName 用户名，最大长度255。authType=2时有效
 @param authPwd 用户名密码，最大长度255。authType=2时有效
 @param proxyType 代理类型。 目前支持 0 socks5代理；1 http代理
 @return 0成功，非0失败
 */
- (NSInteger)setNetworkProxy:(NSString*)proxyHost port:(NSInteger)proxyPort authType:(NSInteger)type name:(NSString*)authName pwd:(NSString*)authPwd ProxyType:(NSInteger)proxyType;

/**
 @brief 保持客户端TCP后台连接3分钟
 @discussion VoIP呼叫开始时打开，呼叫结束时关闭，保证APP在后台3分钟内收到呼叫状态回调
 @param isSandBox 是否打开
 */
- (void)setOpenBackgroudTask:(BOOL)isOpen;

- (void)applicationBeginBackgroundTask:(void(^ __nullable)(void))handler;


/**
 @brief device代理
 @discussion 用于监听通知事件
 */
@property (nonatomic, assign) id<ECDeviceDelegate> delegate;

/**
 @brief 即时消息管理类
 @discussion 用于群组管理，消息发送，录音、放音等操作
 */
@property (nonatomic, readonly, strong) id<ECMessageManager> messageManager;

/**
 @brief VoIP管理类
 @discussion 用于VoIP相关操作；如果SDK只是IM版本，该实例为nil
 */
@property (nonatomic, readonly, strong) id<ECVoIPManager> VoIPManager;

/**
 @brief 会议管理类
 @discussion 用于会议相关操作；如果SDK只是IM版本，该实例为nil
 */
@property (nonatomic, readonly, strong) id<ECMeetingManager> meetingManager;


/**
 @brief 新版会议管理类
 @discussion 用于会议相关操作；如果SDK只是IM版本，该实例为nil
 */
@property (nonatomic, readonly, strong) id<ECConferenceManager> conferenceManager;

/**
 @brief 直播管理类
 @discussion 用于直播相关操作；如果SDK只是IM版本，该实例为nil
 */
@property (nonatomic, readonly, strong) id<ECLiveStreamManager> liveStreamManager;

/**
 @brief 直播聊天室管理类
 @discussion 用于聊天室相关操作
 */
@property (nonatomic, readonly, strong) id<ECLiveChatRoomManager> liveChatRoomManager;
@end
