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

typedef void(^PoporDatePickerDateBlock)(BOOL toToday, NSDate * date);
typedef void(^PoporDatePickerCustomeSelectingBlock)(PoporDatePicker * pdp, NSInteger row, NSInteger component);
typedef void(^PoporDatePickerCustomeBlock)(PoporDatePicker * pdp, NSMutableArray<PoporDatePickerSelectUE *> * selectUeArray);

// 自定义view高度
typedef CGFloat(^PoporDatePickerCustomeDelegate_cellHeight)(PoporDatePicker * pdp, NSInteger component);

// 自定义view
typedef UIView*(^PoporDatePickerCustomeDelegate_cell)(PoporDatePicker * pdp, NSInteger row, NSInteger component, UIView * reusingView);

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
    PoporDatePickerStyle_custom,   // 自定义, 不是时间格式
};

typedef NS_ENUM(NSInteger, PoporDatePickerUIStyle) {
    PoporDatePickerUIStyle_done,          // 只包含一个确定键.
    PoporDatePickerUIStyle_confirmCancel, // 包含 取消、确定和title
};


@interface PoporDatePicker : UIView <UIPickerViewDelegate,UIPickerViewDataSource>

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
@property (nonatomic, copy  ) NSString     * dateFormatter;

// 自定义的选择
@property (nonatomic, strong) NSMutableArray<PoporDatePickerSelectLE *> * customDatasourceArray;// 一个自定义的二维数组, 区别于date
@property (nonatomic, copy  ) PoporDatePickerCustomeSelectingBlock customeSelectingBlock; // 选择过程中的block, 可以参考示例1.
@property (nonatomic, copy  ) PoporDatePickerCustomeBlock customeBlock;

@property (nonatomic, strong) NSMutableArray<PoporDatePickerSelectUE *> * selectUeArray;

@property (nonatomic        ) PoporDatePickerStyle datePickerStyle;
@property (nonatomic        ) PoporDatePickerUIStyle uiStyle;

// 自定义block
@property (nonatomic, copy  ) PoporDatePickerCustomeDelegate_cellHeight customeDelegateCellHeightBlock;
@property (nonatomic, copy  ) PoporDatePickerCustomeDelegate_cell       customeDelegateCellBlock;

// 显示至今的参数
@property (nonatomic        ) BOOL showToToday;// 前提必须是, 为了不紊乱, 必须包括年.
@property (nonatomic, copy  ) NSString * toTodayText;// 默认为 "至今"
@property (nonatomic        ) NSInteger toTodayMaxYear;// 默认为 当前时间的yyyy
@property (nonatomic        ) BOOL isSelectToToday; // 主要用于内部使用: 是否选择了至今

- (void)show;
- (void)dismiss;

+ (NSString *)formatterFromStyle:(PoporDatePickerStyle)datePickerStyle;

@end

// 示例1 :customeSelectingBlock
//datePicker.customeSelectingBlock = ^(PoporDatePicker *pdp, NSInteger row, NSInteger component) {
//    PoporDatePickerSelectUE * minUE = pdp.selectUeArray.firstObject;
//    PoporDatePickerSelectUE * maxUE = pdp.selectUeArray.lastObject;
//    NSInteger minInt = [minUE.text substringToIndex:minUE.text.length-1].integerValue;
//    NSInteger maxInt = [maxUE.text substringToIndex:maxUE.text.length-1].integerValue;
//
//    switch (component) {
//        case 0: {
//            if (maxInt < minInt) {
//                NSInteger toRow = minInt-1;
//                [pdp.datePicker selectRow:minInt-1 inComponent:1 animated:YES];
//
//                PoporDatePickerSelectLE * le = pdp.customDatasourceArray[1];
//                PoporDatePickerSelectUE * ue = le.ueArray[toRow];
//                [pdp.selectUeArray replaceObjectAtIndex:1 withObject:ue];
//            }
//            break;
//        }
//        case 1: {
//            if (maxInt < minInt) {
//                NSInteger toRow = maxInt-1;
//                [pdp.datePicker selectRow:toRow inComponent:0 animated:YES];
//
//                PoporDatePickerSelectLE * le = pdp.customDatasourceArray[0];
//                PoporDatePickerSelectUE * ue = le.ueArray[toRow];
//                [pdp.selectUeArray replaceObjectAtIndex:0 withObject:ue];
//            }
//            break;
//        }
//        default:
//            break;
//    }
//    };
