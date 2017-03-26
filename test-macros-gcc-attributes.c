#define sample(_name, _param) \
	void __call_ ## _name(_param)

#define mymacro(y, x) \
	x ## _field(int superclass(y x))

extern sample(ola,int view1);
extern sample(ate,int view2);

extern void mymacro(int,wow);

void old_function() __attribute__((section(".text.amd64"))) __attribute__((deprecated));

void old_function() {
	int i = 0;
}

/*
   SSID: Suporte_2016
   Secure: WPA2
   Password: :Sup0rt3:12@d!  */
