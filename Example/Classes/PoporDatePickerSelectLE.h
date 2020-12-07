//
//  PoporDatePickerSelectLE.h
//  PoporDatePicker
//
//  Created by popor on 2020/12/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define PdpSelectUEText(text, data) [PoporDatePickerSelectUE initWithText:text d##ata:data]
#define PdpSelectUEAtt (att , data) [PoporDatePickerSelectUE initWithAtt :att  d##ata:data]

@interface PoporDatePickerSelectUE : NSObject

@property (nonatomic, copy  ) NSString * text;
@property (nonatomic, copy  ) NSAttributedString * att;

@property (nonatomic, weak  ) NSObject * data;

+ (PoporDatePickerSelectUE *)initWithText:(NSString * _Nonnull)text data:(NSObject * _Nullable)data;
+ (PoporDatePickerSelectUE *)initWithAtt:(NSAttributedString * _Nonnull)att data:(NSObject * _Nullable)data;

@end

@interface PoporDatePickerSelectLE : NSObject

//@property (nonatomic, copy  ) NSString * _Nullable unitName; // 很难处理, 因为ue.value的长度很难控制.
@property (nonatomic, strong) NSMutableArray<PoporDatePickerSelectUE *> * ueArray;

@end

NS_ASSUME_NONNULL_END
