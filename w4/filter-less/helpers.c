#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
    {
      BYTE r = image[i][j].rgbtRed;
      BYTE g = image[i][j].rgbtGreen;
      BYTE b = image[i][j].rgbtBlue;

      double avg = round(r + g + b) / 3.0;

      image[i][j].rgbtRed = avg;
      image[i][j].rgbtGreen = avg;
      image[i][j].rgbtBlue = avg;
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
    for (int j = 0; j < width; j++)
    {
      BYTE r = image[i][j].rgbtRed;
      BYTE g = image[i][j].rgbtGreen;
      BYTE b = image[i][j].rgbtBlue;

      double sr = round(.393 * r + .769 * g + .189 * b);
      double sg = round(.349 * r + .686 * g + .168 * b);
      double sb = round(.272 * r + .534 * g + .131 * b);

      if (sr > 255) sr = 255;
      if (sg > 255) sg = 255;
      if (sb > 255) sb = 255;
      
      image[i][j].rgbtRed = sr;
      image[i][j].rgbtGreen = sg;
      image[i][j].rgbtBlue = sb;
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
  for (int i = 0; i < height; i++)
    for (int j = 0; j < (width / 2); j++)
    {
      int k = width - j;

      BYTE r = image[i][j].rgbtRed;
      BYTE g = image[i][j].rgbtGreen;
      BYTE b = image[i][j].rgbtBlue;

      BYTE rr = image[i][k].rgbtRed;
      BYTE rg = image[i][k].rgbtGreen;
      BYTE rb = image[i][k].rgbtBlue;


      image[i][j].rgbtRed = rr;
      image[i][j].rgbtGreen = rg;
      image[i][j].rgbtBlue = rb;

      image[i][k].rgbtRed = r;
      image[i][k].rgbtGreen = g;
      image[i][k].rgbtBlue = b;
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
          )
          {
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
