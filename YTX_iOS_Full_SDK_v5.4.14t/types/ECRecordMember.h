//
//  ECRecordMember.h
//  CCPiPhoneSDK
//
//  Created by wangjunping on 2019/5/16.
//  Copyright © 2019 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECEnumDefs.h"
NS_ASSUME_NONNULL_BEGIN

@interface ECRecordMember : NSObject

/**
 @brief 账号ID
 */
@property (nonatomic, copy) NSString* accountId;

/**
 @brief 账号类型
 */
@property (nonatomic, assign) int accountType;

/**
 @brief 多终端登录时的设备类型
 */
@property (nonatomic, assign) ECDeviceType deviceType;

/**
 @brief 1:代表摄像头视频 2:代表共享视频，不带类型为成员视频
 */
@property (nonatomic, assign) int srcType;
@end

NS_ASSUME_NONNULL_END
