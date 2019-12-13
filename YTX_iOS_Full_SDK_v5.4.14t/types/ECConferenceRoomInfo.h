//
//  ECConferenceRoomInfo.h
//  CCPiPhoneSDK
//
//  Created by 王文龙 on 2017/9/30.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECConferenceMemberInfo.h"

@interface ECConferenceRoomInfo : NSObject
/**
 @brief 应用ID
 */
@property (nonatomic, copy) NSString * appId;

/**
 @brief confRoomId
 */
@property (nonatomic, copy) NSString * confRoomId;
/**
 @brief confRoomName
 */
@property (nonatomic, copy) NSString * confRoomName;
/**
 @brief member
 */
@property (nonatomic, retain) ECAccountInfo * member;
/**
 @brief joinState
 */
@property (nonatomic, assign) NSInteger joinState;
/**
 @brief maxMember
 */
@property (nonatomic, assign) NSInteger maxMember;
/**
 @brief createTime
 */
@property (nonatomic, copy) NSString * createTime;
/**
 @brief updateTime
 */
@property (nonatomic, copy) NSString * updateTime;

/**
 @brief 是否启用多终端登录功能，启用后成员 MemberId 字段会有变化  0表示关闭，1表示启用
 */
@property (nonatomic, assign) NSInteger multiTerminal;

@end
