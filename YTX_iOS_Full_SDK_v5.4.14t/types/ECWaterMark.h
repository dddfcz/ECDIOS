//
//  ECWaterMark.h
//  CCPiPhoneSDK
//
//  Created by xt on 2018/6/28.
//  Copyright © 2018年 ronglian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM (NSInteger, ECWaterMarkPosition){
    ECWaterMarkPosition_TopLeft,
    ECWaterMarkPosition_BottomLeft,
    ECWaterMarkPosition_BottomRight,
    ECWaterMarkPosition_TopRight,
};

@interface ECWaterMark : NSObject

@property (nonatomic, copy) NSString *fontFile;           //字体ttf路径
@property (nonatomic, copy) NSString *fontColor;        //字体 RGB  eg. '00ff00'
@property (nonatomic, assign) NSInteger fontSize;       //字体大小  eg. 0~100
@property (nonatomic, copy) NSString *text;               //水印文字  eg. 'Hello watermark'
@property (nonatomic, assign) CGPoint potion;           //水印坐标
@property (nonatomic, copy) NSString *imagePath;     //水印图片路径
@property (nonatomic, assign) ECWaterMarkPosition startPosition;
@property (nonatomic, assign) NSInteger flag;             //'0': image '1': text
@property (nonatomic, assign) NSInteger width;          //视频区域宽
@property (nonatomic, assign) NSInteger height;         //视频区域高

- (NSString *)waterMarkPosition;

@end
