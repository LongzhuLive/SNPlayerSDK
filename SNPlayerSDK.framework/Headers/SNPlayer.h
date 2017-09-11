//
//  SNPrivPlayer.h
//  SNPlayerSDK
//
//  Created by sunshaobing on 2017/2/16.
//  Copyright © 2017年 plu-dev. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNPlayerProtocol.h"


/**
 SNPlayer,...RenderVie is kind of SNPlayerView
 */
@interface SNPlayer : NSObject <SNPlayerProtocol>

#pragma mark - 初始化
/**
 构造方法
 
 @param playerConfig 播放器配置
 @return 返回播放器实例对象
 */
-(nonnull id<SNPlayerProtocol>)initWithPlayerConfig: (nonnull SNPlayerConfig *)playerConfig;
/**
 构造方法
 
 @param playerConfig 播放器配置
 @param renderView 播放器View(为nil时内部生成一个)
 @return 返回播放器实例对象
 */
-(nonnull id<SNPlayerProtocol>)initWithPlayerConfig: (nonnull SNPlayerConfig *)playerConfig andRenderView: (nullable UIView *)renderView;

@end
