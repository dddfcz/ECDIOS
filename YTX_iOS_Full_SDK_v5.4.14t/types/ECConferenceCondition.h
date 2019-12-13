//
//  ECConferenceCondition.h
//  CCPiPhoneSDK
//
//  Created by jiazy on 2017/2/17.
//  Copyright © 2017年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECConferenceInfo.h"
#import "ECStruct.h"

typedef NS_ENUM(NSUInteger,ECConferenceSearchType) {
    
    /** 创建的会议 */
    ECConferenceSearchType_Create = 1,
    
    /** 参与的会议 */
    ECConferenceSearchType_Participate = 2,
    
    /** 创建和参与的会议 */
    ECConferenceSearchType_All = 3,
};

/**
 *  会议获取条件类
 */
@interface ECConferenceCondition : NSObject

/**
 @brief 创建时间起始点 yyyy-MM-dd HH:mm:ss
 */
@property (nonatomic, copy) NSString* createTimeBegin;

/**
 @brief 创建时间终点 yyyy-MM-dd HH:mm:ss
 */
@property (nonatomic, copy) NSString* createTimeEnd;

/**
 @brief 会议类型
 */
@property (nonatomic, assign) ECConferenceType confType;

/**
 @brief 会议类型
 */
@property (nonatomic, assign) ECConferenceMediaType mediaType;

/**
 @brief 会议类型
 */
@property (nonatomic, assign) ECConferenceSearchType searchType;

/**
 @brief 会议id
 */
@property (nonatomic, copy) NSString *confId;

/**
 @brief 会议状态，0: 返回未开始的会议 1: 返回进行中的会议  , 默认-1 全部
 */
@property (nonatomic, assign) int stateInProcess;

/**
 @brief 模糊搜索 confName
 */
@property (nonatomic, copy) NSString *keyWord;

@end
