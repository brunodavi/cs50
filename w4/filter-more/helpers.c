#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  for (int h = 0; h < height; h++)
    for (int w = 0; w < width; w++)
    {
      double r = image[h][w].rgbtRed;
      double g = image[h][w].rgbtGreen;
      double b = image[h][w].rgbtBlue;

      double avg = (r + g + b) / 3.0;

      image[h][w].rgbtRed = avg;
      image[h][w].rgbtGreen = avg;
      image[h][w].rgbtBlue = avg;
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  for (int h = 0; h < height; h++)
    for (int w = 0; w < (width / 2); w++)
    {
      int lw = width - w;

      double r = image[h][w].rgbtRed;
      double g = image[h][w].rgbtGreen;
      double b = image[h][w].rgbtBlue;

      double rr = image[h][lw].rgbtRed;
      double rg = image[h][lw].rgbtGreen;
      double rb = image[h][lw].rgbtBlue;


      image[h][w].rgbtRed = rr;
      image[h][w].rgbtGreen = rg;
      image[h][w].rgbtBlue = rb;

      image[h][lw].rgbtRed = r;
      image[h][lw].rgbtGreen = g;
      image[h][lw].rgbtBlue = b;
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];

  for (int h = 0; h < height; h++)
    for (int w = 0; w < width; w++)
      copy[h][w] = image[h][w];

  for (int h = 0; h < height; h++)
    for (int w = 0; w < width; w++)
    {
      double r = 0.0;
      double g = 0.0;
      double b = 0.0;

      double count = 0.0;

      for (int bh = h-1; bh <= h+1; bh++)
        for (int bw = w-1; bw <= w+1; bw++)
        {
          if (
            bh >= 0 &&
            bw >= 0 &&

            bh <= height &&
            bw <= width
          ) {
            r += copy[bh][bw].rgbtRed;
            g += copy[bh][bw].rgbtGreen;
            b += copy[bh][bw].rgbtBlue;

            count++;
          }
        }

      r = round(r / count);
      g = round(g / count);
      b = round(b / count);

      if (r > 255) r = 255;
      if (g > 255) g = 255;
      if (b > 255) b = 255;

      image[h][w].rgbtRed = r;
      image[h][w].rgbtGreen = g;
      image[h][w].rgbtBlue = b;
    }
}

double sobel(double x, double y) {
  double result = round(
    sqrt(
      (
        (x * x)
        +
        (y * y)
      )
    )
  );

  if (result > 255)
    result = 255;
  else if (result < 0)
    result = 0;

  return result;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
  int gx[3][3] = {
    { -1, 0, 1 },
    { -2, 0, 2 },
    { -1, 0, 1 },
  }; 

  int gy[3][3] = {
    { -1, -2, -1 },
    {  0,  0,  0 },
    {  1,  2,  1 },
  }; 

  RGBTRIPLE copy[height][width];

  for (int h = 0; h < height; h++)
    for (int w = 0; w < width; w++)
      copy[h][w] = image[h][w];

  for (int h = 0; h < height; h++)
    for (int w = 0; w < width; w++)
    {
      double xr = 0.0;
      double xg = 0.0;
      double xb = 0.0;

      double yr = 0.0;
      double yg = 0.0;
      double yb = 0.0;

      for (int bh = h-1, gh = 0; bh <= h+1; bh++, gh++)
        for (int bw = w-1, gw = 0; bw <= w+1; bw++, gw++)
        {
          if (
            bh >= 0 &&
            bw >= 0 &&

            bh <= height &&
            bw <= width
          ) {
            int x = gx[gh][gw];
            int y = gy[gh][gw];

            xr += copy[bh][bw].rgbtRed * x;
            xg += copy[bh][bw].rgbtGreen * x;
            xb += copy[bh][bw].rgbtBlue * x;

            yr += copy[bh][bw].rgbtRed * y;
            yg += copy[bh][bw].rgbtGreen * y;
            yb += copy[bh][bw].rgbtBlue * y;
          }
        }

      double r = sobel(xr, yr);
      double g = sobel(xg, yg);
      double b = sobel(xb, yb);

      image[h][w].rgbtRed = r;
      image[h][w].rgbtGreen = g;
      image[h][w].rgbtBlue = b;
    }
}
