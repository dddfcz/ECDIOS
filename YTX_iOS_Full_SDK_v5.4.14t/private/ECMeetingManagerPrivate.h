//
//  ECMeetingManagerPrivate.h
//  CCPiPhoneSDK
//
//  Created by ronglian on 15/1/26.
//  Copyright (c) 2015年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol ECMeetingManagerPrivate<NSObject>

/**
 @brief 获取当前会议的Callid
 @return 呼叫callid
 */
- (NSString*)getCallIdOfCurMeeting;

/**
 @brief 邀请加入会议是否加密
 @param rtptype 标识是否加密 0 为不加密 1为加密
 */
-(void)setMultimediaMeetingRtpprofiletypeBeforeInviteJoin:(NSInteger) rtptype;

/**
 @brief 视频会议请求某一远端视频
 @param username 用户账号
 @param displayView 显示的view
 @param meetingNumber 房间号
 @param meetingPwd 房间密码
 @param ip 视频源地址
 @param port 视频源端口
 @param crypto 密钥类型
 @param cryptoKey 密钥
 @param completion 执行结果回调block
 */
- (void)requestMemberVideoWithAccount:(NSString*)username andDisplayView:(UIView*)displayView andVideoMeeting:(NSString*)meetingNumber andPwd:(NSString*)meetingPwd andIP:(NSString*)ip andPort:(NSInteger)port crypto:(NSString*)crypto cryptoKey:(NSString*)cryptoKey completion:(void (^)(ECError *error, NSString *meetingNumber,NSString *member))completion;
@end
