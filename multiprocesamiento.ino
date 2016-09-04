
void setup() {
  // put your setup code here, to run once:
  int a = 3;
  auto lambda = [&] (int x) { return x * a; };
  a = 2;
  lambda(5);

}

void loop() {
  // put your main code here, to run repeatedly:

}
