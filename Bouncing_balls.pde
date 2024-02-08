int ballCount = 30;

float[] x = new float[ballCount];
float[] y = new float[ballCount];
float[] xSpeed = new float[ballCount];
float[] ySpeed = new float[ballCount];
float[] size = new float[ballCount];
float[] r = new float[ballCount];
float[] g = new float[ballCount];
float[] b = new float[ballCount];

void setup() {
  size(600, 600);
  for(int i = 0; i < ballCount; i++){
    x[i] = random(width);
    y[i] = random(height);
    xSpeed[i] = random(-5, 5);
    ySpeed[i] = random(-5, 5);
    size[i] = random(5, 20);
    r[i] = random(256);
    g[i] = random(256);
    b[i] = random(256);
  }
}

void draw() {
  background(255);
  for(int i = 0; i < ballCount; i++){
    x[i] += xSpeed[i];
    if(x[i] < 0 || x[i] > width){
      xSpeed[i] *= -1;
    }

    y[i] += ySpeed[i];
    if(y[i] < 0 || y[i] > height){
      ySpeed[i] *= -1;
    }

    fill(r[i], g[i], b[i]);
    ellipse(x[i], y[i], size[i], size[i]);
  }
}
