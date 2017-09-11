//
//  SNPlayerConfig.h
//  SNPlayerSDK
//
//  Created by sunshaobing on 2017/2/16.
//  Copyright © 2017年 plu-dev. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 播放器配置信息
 */
@interface SNPlayerConfig : NSObject


/**
 播放器允许的最大延迟（本地Buffer），默认15秒
 @discussion 延迟超过此数值就追触发追流，此参数需设置为>5秒,建议大于10秒
 */
@property (nonatomic, assign) NSTimeInterval maxBufferLatency;
/**
 播放器追流后的最低延迟（本地Buffer），默认5秒
 @discussion 追流后的会将延迟降低到本数值(>0)，原则上不限制取值，建议大于3秒
 */
@property (nonatomic, assign) NSTimeInterval minBufferLatency;
/**
 是否开启硬件解码，默认关闭
 @discussion ios8以上版本才支持
 */
@property (nonatomic, assign) BOOL hwDecoderEnabled;

+ (SNPlayerConfig *)defaultConfig;

@end
