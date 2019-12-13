//
//  ECRecordInfo.h
//  CCPiPhoneSDK
//
//  Created by xt on 2019/1/9.
//  Copyright © 2019 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ECRecordInfo : NSObject


/**
 @brief 会议id
 */
@property (nonatomic, copy) NSString *confId;

/**
 @brief 文件地址
 */
@property (nonatomic, copy) NSString *fileUrl;

/**
 @brief 录制文件类型 1：音频；2：视频； 3：音视频
 */
@property (nonatomic, assign) int recordType;



///点对点录像时字段///

/**
 @brief 会话ID
 */
@property (nonatomic, copy) NSString *sessionId;

/**
 @brief 文件下载地址
 */
@property (nonatomic, copy) NSString *downloadUrl;

/**
 @brief 录像文件名
 */
@property (nonatomic, copy) NSString *fullname;

/**
 @brief 开始时间
 */
@property (nonatomic, copy) NSString *startTime;

/**
 @brief 停止时间
 */
@property (nonatomic, copy) NSString *stopTime;

/**
 @brief 录像时长
 */
@property (nonatomic, assign) int duration;

/**
 @brief 任务状态
 */
@property (nonatomic, copy) NSString *status;

/**
 @brief 大小
 */
@property (nonatomic, assign) int size;

/**
 @brief 类型标签
 */
@property (nonatomic, copy) NSString *type;

@end

NS_ASSUME_NONNULL_END
