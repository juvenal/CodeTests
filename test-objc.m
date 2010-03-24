/*
 *
 *
 *
 */

#import <objc/Object.h>

@interface MyClass: Object
    int times;
@end

@implementation MyClass
    -(void) display:(int)qtd msg:(char *)message; {
        int i = 0;

        for (i = 0; i < qtd; i++) {
            if (i > 0) {
                printf("%s %d times!\n", message, i+1);
            }
            else {
                printf("%s %d time!\n", message, i+1);
            }
        }
    }
@end

int main(int argc, char *argv[]) {
    MyClass *message = [MyClass new];
    [message display:10 msg:"Eita mundo! Oia nois aqui"];
    return 0;
}
