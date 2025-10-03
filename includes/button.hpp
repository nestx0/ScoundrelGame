#include "raylib.h"
#include <string>

#ifndef BUTTON_H
#define BUTTON_H

class Button {
private:
  Rectangle _body;
  Texture2D *_design;
  Color _normalColor, _hoveredColor, _clickedColor;
  std::string _text;

public:
  Button(float x0, float y0, float width, float height,
         const std::string &text = "", Color normalColor = GRAY,
         Color hoverColor = LIGHTGRAY, Color clickedColor = DARKGRAY,
         Texture2D *texture = nullptr);

  Rectangle getRectangle() const;
  Texture2D *getTexture() const;
  Color getNormalColor() const;
  Color getHoverColor() const;
  Color getClickedColor() const;
  Color getActualColor() const;
  std::string getText() const;

  void setColors(Color normalColor, Color hoverColor, Color clickColor);
  void setTexture(Texture2D *texture);
  void setPosition(float x, float y);
  void setSize(float width, float height);
  void setText(const std::string &text);

  bool isHovered() const;
  bool isClicked() const;

  void drawButton() const;
  void drawText() const;
};

#endif
