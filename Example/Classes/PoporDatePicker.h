//
//  WSDatePickerView.h
//  WSDatePicker
//
//  Created by iMac on 17/2/23.
//  Copyright © 2017年 zws. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSDate+PoporDatePicker.h"

#define PdpRGBA(r, g, b, a) [UIColor colorWithRed:(r / 255.0) green:(g / 255.0) blue:(b / 255.0) alpha:a]

/**
 *  弹出日期类型
 */
typedef NS_ENUM(int, PoporDatePickerStyle) {
    PoporDatePickerStyle_YMDHM = 0,//年月日时分
    PoporDatePickerStyle_MDHM,     //月日时分
    PoporDatePickerStyle_YMD,      //年月日
    PoporDatePickerStyle_YM,       //年月
    PoporDatePickerStyle_MD,       //月日
    PoporDatePickerStyle_HM,       //时分
    PoporDatePickerStyle_Y,        //年
    PoporDatePickerStyle_M,        //月
    PoporDatePickerStyle_DHM,      //日时分
};


@interface PoporDatePicker : UIView

/**
 *  确定按钮颜色
 */
@property (nonatomic,strong)UIColor *doneBTColor;
/**
 *  年-月-日-时-分 文字颜色(默认橙色)
 */
@property (nonatomic,strong)UIColor *dateLabelColor;
/**
 *  滚轮日期颜色(默认黑色)
 */
@property (nonatomic,strong)UIColor *datePickerColor;

/**
 *  限制最大时间（默认2099）datePicker大于最大日期则滚动回最大限制日期
 */
@property (nonatomic, retain) NSDate *maxLimitDate;
/**
 *  限制最小时间（默认0） datePicker小于最小日期则滚动回最小限制日期
 */
@property (nonatomic, retain) NSDate *minLimitDate;

/**
 *  大号年份字体颜色(默认灰色)想隐藏可以设置为clearColor
 */
@property (nonatomic, retain) UIColor *yearLabelColor;

/**
 *  隐藏背景年份文字
 */
@property (nonatomic, assign) BOOL hideBackgroundYearLabel;

/**
 默认滚动到当前时间
 */
- (instancetype)initWithDateStyle:(PoporDatePickerStyle)datePickerStyle CompleteBlock:(void(^)(NSDate *))completeBlock;

/**
 滚动到指定的的日期
 */
- (instancetype)initWithDateStyle:(PoporDatePickerStyle)datePickerStyle scrollToDate:(NSDate *)scrollToDate CompleteBlock:(void(^)(NSDate *))completeBlock;

- (void)show;

@end

