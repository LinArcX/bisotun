#include <locale.h>
#include <string.h>
#include "bisotun.h"

float pageSizeWidth;
float pageSizeHeight;

BstnProperties *prop;
struct pdf_object *page;

int
openBisotun(BstnProperties *properties)
{
  prop = properties;

  struct pdf_info info;
  strncpy(info.creator, prop->author, ARRAY_SIZE * sizeof(char) - 1); info.creator[ARRAY_SIZE - 1] = 0;
  strncpy(info.producer, prop->author, ARRAY_SIZE * sizeof(char) - 1); info.producer[ARRAY_SIZE - 1] = 0;
  strncpy(info.title, prop->title, ARRAY_SIZE * sizeof(char) - 1); info.title[ARRAY_SIZE - 1] = 0;
  strncpy(info.author, prop->author, ARRAY_SIZE * sizeof(char) - 1); info.author[ARRAY_SIZE - 1] = 0;
  strncpy(info.subject, prop->subject, ARRAY_SIZE * sizeof(char) - 1); info.subject[ARRAY_SIZE - 1] = 0;

  if(prop->pageSize == A3)
  {
    pageSizeWidth =  PDF_A3_WIDTH;
    pageSizeHeight =  PDF_A3_HEIGHT;
  }
  else if(prop->pageSize == A4)
  {
    pageSizeWidth =  PDF_A4_WIDTH;
    pageSizeHeight =  PDF_A4_HEIGHT;
  }
  else if(prop->pageSize == LETTER)
  {
    pageSizeWidth =  PDF_LETTER_WIDTH;
    pageSizeHeight =  PDF_LETTER_HEIGHT;
  }

  prop->position.init.x = prop->margin.left;
  prop->position.init.y = pageSizeHeight - prop->margin.top;

  prop->pdf = pdf_create(pageSizeWidth, pageSizeHeight, &info);
  if (!prop->pdf) 
  {
    fprintf(stderr, "Unable to create PDF\n");
    pdf_destroy(prop->pdf);
    return 0;
  }

  if (pdf_width(prop->pdf) != pageSizeWidth || pdf_height(prop->pdf) != pageSizeHeight) 
  {
    fprintf(stderr, "PDF Size mismatch: %fx%f\n", pdf_width(prop->pdf), pdf_height(prop->pdf));
    pdf_destroy(prop->pdf);
    return 0;
  }

  setlocale(LC_ALL, "");

  pdf_clear_err(prop->pdf);
  return 1;
}

void
saveBisotun()
{
  pdf_save(prop->pdf, prop->title);
}

int
closeBisotun()
{
  int err;
  const char *err_str = pdf_get_err(prop->pdf, &err);
  if (err_str) 
  {
    fprintf(stderr, "PDF Error: %d - %s\n", err, err_str);
    pdf_destroy(prop->pdf);
    return 0;
  }
  pdf_destroy(prop->pdf);
  return 1;
}

BstnPoint initPosition()
{
  BstnPoint point;
  point.x = prop->position.init.x;
  point.y = prop->position.init.y;
  return point;
}

BstnPoint currentPosition()
{
  BstnPoint point;
  point.x = prop->position.current.x;
  point.y = prop->position.current.y;
  return point;
}

void
increaseX(int number)
{
  prop->position.current.x += number;
}

void
increaseY(int number)
{
  prop->position.current.x = prop->position.init.x;
  prop->position.current.y += number;
}

void
increaseYKeepLatestX(int number)
{
  prop->position.current.y += number;
}

void
genPageNumber()
{
  char chCurrentPageNumber [41];
  sprintf(chCurrentPageNumber, "%d", prop->pageNumber.currentNumber++);

  if(prop->pageNumber.position == TOP_LEFT)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 prop->margin.top,
                 pageSizeHeight - (prop->margin.top / 2) - (prop->pageNumber.fontSize / 2),
                 PDF_RGB(0, 0, 0));
  } 

  if(prop->pageNumber.position == TOP_CENTER)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 (pageSizeWidth / 2) - (prop->pageNumber.fontSize / 2),
                 pageSizeHeight - (prop->margin.top / 2),
                 PDF_RGB(0, 0, 0));
  }
  if(prop->pageNumber.position == TOP_RIGHT)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 (pageSizeWidth) - (prop->margin.top / 2) - (prop->pageNumber.fontSize / 2),
                 pageSizeHeight - (prop->margin.top / 2),
                 PDF_RGB(0, 0, 0));
  }
  if(prop->pageNumber.position == LEFT)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 (prop->margin.left / 2) + (prop->pageNumber.fontSize / 2),
                 (pageSizeHeight / 2) + (prop->pageNumber.fontSize / 2),
                 PDF_RGB(0, 0, 0));
  }
  if(prop->pageNumber.position == RIGHT)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 pageSizeWidth - (prop->margin.left / 2) - (prop->pageNumber.fontSize / 2),
                 (pageSizeHeight / 2) + (prop->pageNumber.fontSize / 2),
                 PDF_RGB(0, 0, 0));
  }
  if(prop->pageNumber.position == BOTTOM_LEFT)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 (prop->margin.left / 2) + (prop->pageNumber.fontSize / 2),
                 (prop->margin.bottom / 2) + (prop->pageNumber.fontSize / 2),
                 PDF_RGB(0, 0, 0));
  }
  if(prop->pageNumber.position == BOTTOM_CENTER)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 (pageSizeWidth / 2) - (prop->pageNumber.fontSize / 2),
                 (prop->margin.bottom / 2) + (prop->pageNumber.fontSize / 2),
                 PDF_RGB(0, 0, 0));
  }
  if(prop->pageNumber.position == BOTTOM_RIGHT)
  {
    pdf_add_text(prop->pdf,
                 page,
                 chCurrentPageNumber,
                 prop->pageNumber.fontSize,
                 pageSizeWidth - (prop->margin.right / 2) - (prop->pageNumber.fontSize / 2),
                 (prop->margin.bottom / 2) + (prop->pageNumber.fontSize / 2),
                 PDF_RGB(0, 0, 0));
  }
}

void
genPage()
{
  prop->position.current.x = prop->position.init.x;
  prop->position.current.y = prop->position.init.y;

  page = pdf_append_page(prop->pdf);

  if(prop->pageNumber.autoGenerate == true)
  {
    genPageNumber();
  }
}

void
genLine(
        int offsetBeforeX, int offsetBeforeY,
        int offsetAfterX, int offsetAfterY,
        bool keepXPosition,
        int width, float height)
{
  // TODO: color should be part of BstnProperties
  pdf_add_line(prop->pdf,
               page,
               prop->position.current.x + offsetBeforeX,
               prop->position.current.y + offsetBeforeY,
               prop->position.current.x + width,
               prop->position.current.y,
               height,
               PDF_RGB(0, 0, 0));
  increaseX(offsetAfterX);
  if(keepXPosition)
  {
    increaseYKeepLatestX(offsetAfterY);
  }
  else
  {
    increaseY(offsetAfterY);
  }
}

void genIcon(
              int offsetBeforeX, int offsetBeforeY,
              int offsetAfterX, int offsetAfterY,
              bool keepXPosition,
              int size, const char* path)
{
  pdf_add_image_file(prop->pdf, page, prop->position.current.x + offsetBeforeX, prop->position.current.y + offsetBeforeY, size, size, path);

  increaseX(offsetAfterX);
  if(keepXPosition)
  {
    increaseYKeepLatestX(offsetAfterY);
  }
  else
  {
    increaseY(offsetAfterY);
  }
}

void
genText(int offsetBeforeX, int offsetBeforeY,
                  int offsetAfterX, int offsetAfterY,
                  bool keepXPosition,
                  int fontSize, bool isBold, bool isItalic, const char* text)
{
  if(isBold)
  {
    pdf_set_font(prop->pdf, prop->font.bold.name);
  }
  else
  {
    pdf_set_font(prop->pdf, prop->font.regular.name);
  }
  pdf_add_text(prop->pdf, page, text, fontSize, prop->position.current.x + offsetBeforeX, prop->position.current.y + offsetBeforeY, PDF_RGB(0, 0, 0));
  increaseX(offsetAfterX);
  if(keepXPosition)
  {
    increaseYKeepLatestX(offsetAfterY);
  }
  else
  {
    increaseY(offsetAfterY);
  }
}
