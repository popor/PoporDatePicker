//
//  PoporDatePickerSelectLE.m
//  PoporDatePicker
//
//  Created by popor on 2020/12/7.
//

#import "PoporDatePickerSelectLE.h"

@implementation PoporDatePickerSelectUE

+ (PoporDatePickerSelectUE *)initWithText:(NSString * _Nonnull)text data:(NSObject * _Nullable)data {
    PoporDatePickerSelectUE * ue = [PoporDatePickerSelectUE new];
    ue.text = text;
    ue.data = data;
 
    return ue;
}

+ (PoporDatePickerSelectUE *)initWithAtt:(NSAttributedString * _Nonnull)att data:(NSObject * _Nullable)data {
    PoporDatePickerSelectUE * ue = [PoporDatePickerSelectUE new];
    ue.att  = att;
    ue.data = data;
    
    return ue;
}

@end

@implementation PoporDatePickerSelectLE

@end
