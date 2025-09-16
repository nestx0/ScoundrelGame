#include "raylib.h"
#include <string>

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
private:
    Rectangle _body;
    Texture2D *_design;
    Color _normalColor, _hoveredColor, _clickedColor;
    std::string _text;

public:
    Button();
    Button(int x0, int y0, int width, int height, const std::string &text, Color normalColor = GRAY, Color hoverColor = LIGHTGRAY, Color clickedColor = DARKGRAY, Texture2D *texture = nullptr);

    Rectangle getRectangle() const;
    Texture2D *getTexture() const;
    Color getColor() const;

    void setColors(Color normalColor, Color hoverColor, Color clickColor);
    void setTexture(Texture2D *texture);
    void setPosition(int x, int y);
    void setSize(int width, int height);
    void setText(const std::string &text);

    bool isHovered() const;
    bool isClicked() const;

    void drawButton() const;
};

#endif