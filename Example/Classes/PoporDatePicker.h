//
//  WSDatePickerView.h
//  WSDatePicker
//
//  Created by iMac on 17/2/23.
//  Copyright © 2017年 zws. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSDate+PoporDatePicker.h"
#import "PoporDatePickerSelectLE.h"

#define PdpRGBA(r, g, b, a) [UIColor colorWithRed:(r / 255.0) green:(g / 255.0) blue:(b / 255.0) alpha:a]

@class PoporDatePicker;

typedef void(^PoporDatePickerDateBlock)(NSDate *);
typedef void(^PoporDatePickerCustomeBlock)(PoporDatePicker * pdp, NSMutableArray<PoporDatePickerSelectUE *> * selectUeArray);

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

typedef NS_ENUM(NSInteger, PoporDatePickerUIStyle) {
    PoporDatePickerUIStyle_done,          // 只包含一个确定键.
    PoporDatePickerUIStyle_confirmCancel, // 包含 取消、确定和title
};


@interface PoporDatePicker : UIView

/**
 *  确定按钮颜色
 */
@property (nonatomic, strong) UIColor *doneBTColor;
/**
 *  年-月-日-时-分 文字颜色(默认橙色)
 */
@property (nonatomic, strong) UIColor *dateLabelColor;
/**
 *  滚轮日期颜色(默认黑色)
 */
@property (nonatomic, strong) UIColor *datePickerColor;

/**
 *  限制最大时间（默认2099）datePicker大于最大日期则滚动回最大限制日期
 */
@property (nonatomic, strong) NSDate *maxLimitDate;
/**
 *  限制最小时间（默认0） datePicker小于最小日期则滚动回最小限制日期
 */
@property (nonatomic, strong) NSDate *minLimitDate;

/**
 *  大号年份字体颜色(默认灰色)想隐藏可以设置为clearColor
 */
@property (nonatomic, strong) UIColor *yearLabelColor;

/**
 *  隐藏背景年份文字
 */
@property (nonatomic        ) BOOL hideBackgroundYearLabel;

/**
 *  底部距离边界的距离默认为10
 */
@property (nonatomic        ) CGFloat leftRightGap; // 左右边界默认为10;
@property (nonatomic        ) CGFloat bottomGap;    // 默认为10;

@property (nonatomic        ) CGFloat bottomViewCorner;    // 默认为8
@property (nonatomic        ) UIRectCorner bottomRectCorner; // 默认为UIRectCornerAllCorners;

@property (nonatomic        ) CGFloat topBtLHeight; // 默认为40
@property (nonatomic        ) CGFloat bottomBtHeight; // 默认为40

@property (nonatomic, strong) UIView       * bottomView;
@property (nonatomic, strong) UILabel      * showYearLabel;

// 第一种模式
@property (nonatomic, strong) UIButton     * doneBT;

// 第二种模式
@property (nonatomic, strong) UIView       * topLineView;
@property (nonatomic, strong) UIButton     * confirmBT;
@property (nonatomic, strong) UIButton     * cancleBT;
@property (nonatomic, strong) UILabel      * titleL;

// 默认的时间选择
@property (nonatomic, strong) UIPickerView * datePicker;
@property (nonatomic, strong) NSDate       * scrollToDate;//滚到指定日期
@property (nonatomic, copy  ) PoporDatePickerDateBlock doneBlock;

// 自定义的选择
@property (nonatomic, strong) NSMutableArray<PoporDatePickerSelectLE *> * customDatasourceArray;// 一个自定义的二维数组, 区别于date
@property (nonatomic, copy  ) PoporDatePickerCustomeBlock customeBlock;
@property (nonatomic, strong) NSMutableArray<PoporDatePickerSelectUE *> * selectUeArray;

@property (nonatomic        ) PoporDatePickerStyle datePickerStyle;
@property (nonatomic        ) PoporDatePickerUIStyle uiStyle;


- (void)show;
- (void)dismiss;

@end

