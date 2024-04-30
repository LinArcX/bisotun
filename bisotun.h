#ifndef DAFTAR_H
#define DAFTAR_H

#include <stdbool.h>
#include "PDFGen/pdfgen.h"

#define ARRAY_SIZE 64

typedef enum dftPageNumberPosition
{
  TOP_LEFT,
  TOP_CENTER,
  TOP_RIGHT,
  LEFT,
  RIGHT,
  BOTTOM_LEFT,
  BOTTOM_CENTER,
  BOTTOM_RIGHT
} BstnPageNumberPosition;

typedef struct dftFontType
{
  int size;
  char name[ARRAY_SIZE];
  char color[ARRAY_SIZE];
} BstnFontType;

typedef struct dftFont
{
  BstnFontType regular;
  BstnFontType bold;
  BstnFontType italic;
} BstnFont;

typedef enum dftPageSize
{
  A3,
  A4,
  LETTER,
} BstnPageSize;

typedef struct dftPoint
{
  int x;
  int y;
} BstnPoint;

typedef struct dftPosition
{
  BstnPoint init;
  BstnPoint current;
} BstnPosition;

typedef struct dftMargin
{
  int left;
  int right;
  int top;
  int bottom;
} BstnMargin;

typedef struct dftPageNumber
{
  int fontSize;
  int currentNumber;
  BstnPageNumberPosition position;
} BstnPageNumber;

typedef struct dftProperties
{
  BstnFont font;
  BstnMargin margin;
  BstnPosition position;
  BstnPageSize pageSize;
  BstnPageNumber pageNumber;

  char title[ARRAY_SIZE];
  char author[ARRAY_SIZE];
  char subject[ARRAY_SIZE];

  struct pdf_doc *pdf;
} BstnProperties;

int openBisotun(BstnProperties *prop);
void saveBisotun(BstnProperties *prop);
int closeDafter(BstnProperties *prop);

BstnPoint initPosition(BstnProperties *prop);
BstnPoint currentPosition(BstnProperties *prop);

void increaseX(BstnProperties *prop, int number);
void increaseY(BstnProperties *prop, int number);
void increaseYKeepLatestX(BstnProperties *prop, int number);

void genPage(BstnProperties *prop, struct pdf_object *page);
void genPageNumber(BstnProperties *prop, struct pdf_object *page);

void genLine(BstnProperties *prop,
              struct pdf_object *page,
              int offsetBeforeX, int offsetBeforeY,
              int offsetAfterX, int offsetAfterY,
              bool keepXPosition,
              int width, float height);

void genIcon(BstnProperties *prop,
              struct pdf_object *page,
              int offsetBeforeX, int offsetBeforeY,
              int offsetAfterX, int offsetAfterY,
              bool keepXPosition,
              int size, const char* path);

void genText(BstnProperties *prop,
              struct pdf_object *page,
              int offsetBeforeX, int offsetBeforeY,
              int offsetAfterX, int offsetAfterY,
              bool keepXPosition,
              int fontSize, bool isBold, bool isItalic, const char* text);

#endif
