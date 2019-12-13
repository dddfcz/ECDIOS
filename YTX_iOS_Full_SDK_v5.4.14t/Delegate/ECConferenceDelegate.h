//
//  ECConferenceDelegate.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/2/13.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECDelegateBase.h"
#import "ECConferenceNotification.h"
#import "ECConferenceMemberInfo.h"

@protocol ECConferenceDelegate <ECDelegateBase>

- (void) onReceivedConferenceNotification:(ECConferenceNotification*)info;

//@{@"confId":@"", @"callType":@(1), @"eventType":@(1)}
- (void)onReceivedThreePartNotification:(NSDictionary *)info;

- (void) onReceivedConferenceVoiceMemberNotification:(NSDictionary *)info UNAVAILABLE_ATTRIBUTE;

- (void) onReceivedConferenceVoiceMemberWithID:(NSString *)confId members:(NSArray *)members;

/**
 @brief 视频分辨率发生改变
 @param meetingId    会议id
 @param member       成员账号
 @param type         1 会议，2 会议共享
 @param width        宽度
 @param height       高度
 @param videoSource  视频源地址
 */
- (void)onCallVideoRatioChanged:(NSString *)meetingid andMember:(NSString *)member andType:(int)type andWidth:(NSInteger)width andHeight:(NSInteger)height andVideoSource:(NSString*)videoSource EC_DEPRECATED_IOS(5.4.0, 5.4.1,"Use -onCallVideoRatioChanged:andAccount:andType:andWidth:andHeight:andVideoSource:");

/**
 @brief 视频分辨率发生改变
 @param confId    会议id
 @param member       成员账号
 @param type         1 会议，2 会议共享
 @param width        宽度
 @param height       高度
 @param videoSource  视频源地址
 */
- (void)onCallVideoRatioChanged:(NSString *)confId andAccount:(ECAccountInfo *)account andType:(int)type andWidth:(NSInteger)width andHeight:(NSInteger)height andVideoSource:(NSString*)videoSource;

/**
 @brief
 
 @param postion 位置信息{@"xPos":@(123), @"yPos":@(456)}
 */
-(void)onReceiveSharePosition:(NSDictionary *)postion;

@end
