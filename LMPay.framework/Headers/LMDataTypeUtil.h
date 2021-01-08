//
//  LMDataTypeUtil.h
//  LemaAPI
//
//  Created by adam on 2019/3/18.
//

#import <Foundation/Foundation.h>

#define ConverString(dict, keys) [LMDataTypeUtil fuckString:dict key:keys];
#define ConverDictionary(dict, keys) [LMDataTypeUtil fuckDictionary:dict key:keys];
#define ConverArray(dict, keys) [LMDataTypeUtil fuckArray:dict key:keys];
#define ConverInt(dict, keys) [LMDataTypeUtil fuckInt:dict key:keys];
#define ConverDouble(dict, keys) [LMDataTypeUtil fuckDouble:dict key:keys];
#define ConverFloat(dict, keys) [LMDataTypeUtil fuckFloat:dict key:keys];
#define ConverInt64(dict, keys) [LMDataTypeUtil fuckLongLong:dict key:keys];
#define ConverBoolean(dict, keys) [LMDataTypeUtil fuckBoolean:dict key:keys];

#define DataToJSONDictionary(data) [LMDataTypeUtil JSONobjectWithData:data];

@interface LMDataTypeUtil : NSObject

+ (BOOL)isNSString:(NSObject*)obj;
+ (NSString*)fuckString:(NSDictionary*)dict key:(NSString*)key;
+ (NSDictionary*)fuckDictionary:(NSDictionary*)dict key:(NSString*)key;
+ (NSArray*)fuckArray:(NSDictionary*)dict key:(NSString*)key;
+ (int)fuckInt:(NSDictionary*)dict key:(NSString*)key;
+ (float)fuckFloat:(NSDictionary*)dict key:(NSString*)key;
+ (long long)fuckLongLong:(NSDictionary*)dict key:(NSString*)key;
+ (BOOL)fuckBoolean:(NSDictionary*)dict key:(NSString*)key;
+ (double)fuckDouble:(NSDictionary*)dict key:(NSString*)key;

+ (NSDictionary*)JSONobjectWithData:(NSData*)data;

@end

