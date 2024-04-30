#include <string.h>
#include "../bisotun.h"

#define LINE_WIDTH 500
#define LINE_HEIGHT 0.95

#define H0 20
#define H1 18
#define H2 16
#define H3 14
#define PARAGRAPH 13

#define DOT_SIZE 40
#define DASH_SIZE 24
#define H1_SPACES -10
#define LINE_SPACES -20
#define SPACE_PARAGRAPH -20
#define SPACE_SECTION -35

struct pdf_object *firstPage;

void
contactInformation(BstnProperties* prop, struct pdf_object * page)
{
  genText(prop, page, 0, 0, 0, H1_SPACES, true, H1, true, false, "Contact Information"); 
  genLine(prop, page, 0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genIcon(prop, page, 0, -3, -3, 0, true, H1, "./data/person.png");
  genText(prop, page, 25, 0, 0, 0, false, PARAGRAPH, false, false, "Sepehr Mirzakhani"); 

  genIcon(prop, page, 250, -3, 0, 0, true, H2, "./data/mail.png");
  genText(prop, page, 275, 1, 0, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "sepehr.mirzakhani@venus.com"); 

  genIcon(prop, page, 250, -3, 0, 0, true, H2, "./data/phone.png");
  genText(prop, page, 275, 1, 0, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "(01) 101-1010"); 

  genIcon(prop, page, 2, 15, -3, 0, false, H2, "./data/home.png");
  genText(prop, page, 25, 18, 0, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "Venus, Solar system"); 

  genIcon(prop, page, 0, 10, -3, 0, false, H0, "./data/linkedin.png");
  genText(prop, page, 25, 16, 0, SPACE_SECTION + 20, false, PARAGRAPH, false, false, "linkedin.com/in/sepehr-mirzakhani"); 
}

void
education(BstnProperties* prop, struct pdf_object * page)
{
  genText(prop, page, 0, 0, 0, H1_SPACES, true, H1, true, false, "Education"); 
  genLine(prop, page, 0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  // university
  genText(prop, page, 0, 2, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 13, 0, false, H2, true, false, "Phobos university, Mars"); 
  genText(prop, page, 250, 0, 13, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "(October 2044 - September 2048)"); 
  genText(prop, page, 20, 0, 13, 0, false, PARAGRAPH, true, false, "Major:"); 
  genText(prop, page, 70, 0, 13, -18, false, PARAGRAPH, false, false, "Software engineering  (full scholarship)"); 
  genText(prop, page, 20, 0, 13, 0, false, PARAGRAPH, true, false, "GPA:"); 
  genText(prop, page, 70, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "1.8"); 

  // high-school
  genText(prop, page, 0, 2, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 13, 0, false, H2, true, false, "Triton high-school, Neptune"); 
  genText(prop, page, 250, 0, 13, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "(2043)"); 
  genText(prop, page, 20, 0, 13, 0, false, PARAGRAPH, true, false, "Major:"); 
  genText(prop, page, 70, 0, 13, -18, false, PARAGRAPH, false, false, "Diploma in Mathematics"); 
  genText(prop, page, 20, 0, 13, 0, false, PARAGRAPH, true, false, "GPA:"); 
  genText(prop, page, 70, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "1.2"); 
}

void
languageSkills(BstnProperties* prop, struct pdf_object * page)
{
  genText(prop, page, 0, 0, 0, H1_SPACES, true, H1, true, false, "Language Skills"); 
  genLine(prop, page, 0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(prop, page, 0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 13, 0, false, H3, true, false, "English:"); 
  genText(prop, page, 70, 0, 30, 0, false, PARAGRAPH, false, false, "IELTS 8"); 
 
  genText(prop, page, 160, 3, 13, 0, false, DOT_SIZE, false, false, "."); 
  genText(prop, page, 175, 0, 13, 0, false, H3, true, false, "Persian:"); 
  genText(prop, page, 230, 0, 13, 0, false, PARAGRAPH, false, false, "Native"); 

  genText(prop, page, 310, 3, 13, 0, false, DOT_SIZE, false, false, "."); 
  genText(prop, page, 325, 0, 13, 0, false, H3, true, false, "French:"); 
  genText(prop, page, 380, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "Elementary"); 
}

void
researchInterests(BstnProperties* prop, struct pdf_object * page)
{
  genText(prop, page, 0, 0, 0, H1_SPACES, true, H1, true, false, "Research interests"); 
  genLine(prop, page, 0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(prop, page, 0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 30, 0, false, PARAGRAPH, false, false, "Operating system development"); 
  genText(prop, page, 260, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 263, 0, 30, SPACE_SECTION, false, PARAGRAPH, false, false, "Progamming languages"); 
}

void
honorsAndAwards(BstnProperties* prop, struct pdf_object * page)
{
  genText(prop, page, 0, 0, 0, H1_SPACES, true, H1, true, false, "Honors and awards"); 
  genLine(prop, page, 0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(prop, page, 0, -1, 13, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 0, 0, 30, SPACE_SECTION, false, PARAGRAPH, false, false, "Ranked 42 among 42777 participants in the nationwide enterance exam [2043]"); 
}

void
trainingCoursesAndCertifications(BstnProperties* prop, struct pdf_object * page)
{
  genText(prop, page, 0, 0, 0, H1_SPACES, true, H1, true, false, "Training courses and certifications"); 
  genLine(prop, page, 0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(prop, page, 0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 13, LINE_SPACES, false, H2, true, false, "Less is more"); 
 
  genText(prop, page, 20, 0, 13, 0, true, H3, true, false, "By:"); 
  genText(prop, page, 30, 0, 13, 0, false, PARAGRAPH, false, false, "His father"); 

  genText(prop, page, 345, 0, 13, 0, false, H3, true, false, "Issued:"); 
  genText(prop, page, 390, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "2030"); 

  genText(prop, page, 0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 13, LINE_SPACES, false, H2, true, false, "How to love yourself?"); 
 
  genText(prop, page, 20, 0, 13, 0, true, H3, true, false, "By:"); 
  genText(prop, page, 30, 0, 13, 0, false, PARAGRAPH, false, false, "Her mother"); 

  genText(prop, page, 345, 0, 13, 0, false, H3, true, false, "Issued:"); 
  genText(prop, page, 390, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "2029"); 
}

void
personalSkills(BstnProperties* prop, struct pdf_object * page)
{
  genText(prop, page, 0, 0, 0, H1_SPACES, true, H1, true, false, "Personal skills"); 
  genLine(prop, page, 0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(prop, page, 0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 13, LINE_SPACES, false, H2, true, false, "Soft skills"); 
  genText(prop, page, 20, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 20, 0, 30, 0, false, PARAGRAPH, false, false, "Careless"); 
  genText(prop, page, 140, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 140, 0, 30, 0, false, PARAGRAPH, false, false, "Smilling"); 
  genText(prop, page, 250, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 250, 0, 30, 0, false, PARAGRAPH, false, false, "Happy"); 
  genText(prop, page, 360, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 360, 0, 30, LINE_SPACES, false, PARAGRAPH, false, false, "Easygoing"); 

  genText(prop, page, 0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(prop, page, 0, 0, 10, LINE_SPACES, false, H2, true, false, "Hard skills"); 
  genText(prop, page, 20, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 20, 0, 30, 0, false, PARAGRAPH, false, false, "Assembly"); 
  genText(prop, page, 100, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 100, 0, 30, 0, false, PARAGRAPH, false, false, "c"); 
  genText(prop, page, 140, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 140, 0, 30, 0, false, PARAGRAPH, false, false, "sepehr-lang"); 
  genText(prop, page, 230, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(prop, page, 230, 0, 30, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "zaal os"); 
}
 
int
main(int argc, char *argv[])
{
  BstnProperties prop;
  prop.margin.top = 35;
  prop.margin.bottom = prop.margin.top;
  prop.margin.left = 30;
  prop.margin.right = prop.margin.left;
  prop.pageSize = A4;
  prop.pageNumber.position = BOTTOM_CENTER;
  prop.pageNumber.fontSize = 12;
  prop.pageNumber.currentNumber = 1;

  // Supported fonts by PDFGen:
  //   Courier, Courier-Bold, Courier-BoldOblique, Courier-Oblique,
  //   Helvetica, Helvetica-Bold, Helvetica-BoldOblique, Helvetica-Oblique,
  //   Times-Roman, Times-Bold, Times-Italic, Times-BoldItalic, Symbol or ZapfDingbats
  char* fontRegular = "Times-Roman";
  strncpy(prop.font.regular.name, fontRegular, strnlen(fontRegular, ARRAY_SIZE - 1)); 
 
  char* fontBold = "Times-Bold";
  strncpy(prop.font.bold.name, fontBold, strnlen(fontBold, ARRAY_SIZE - 1)); 

  char* fontItalic = "Times-Italic";
  strncpy(prop.font.italic.name, fontItalic, strnlen(fontItalic, ARRAY_SIZE - 1)); 

  char* title = "resume.pdf";
  strncpy(prop.title, title, strnlen(title, ARRAY_SIZE - 1)); 
  char* author = "sepehr";
  strncpy(prop.author, author, strnlen(author, ARRAY_SIZE - 1)); 
  char* subject = "resume";
  strncpy(prop.author, subject, strnlen(subject, ARRAY_SIZE - 1)); 

  if(openBisotun(&prop))
  {
    genPage(&prop, firstPage);
    {
      contactInformation(&prop, firstPage);
      education(&prop, firstPage);
      languageSkills(&prop, firstPage);
      researchInterests(&prop, firstPage);
      honorsAndAwards(&prop, firstPage);
      trainingCoursesAndCertifications(&prop, firstPage);
      personalSkills(&prop, firstPage);
      genPageNumber(&prop, firstPage);
    }
    // save
    saveBisotun(&prop);
  }
  closeDafter(&prop);
  return 0;
}
