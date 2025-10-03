#include "../includes/button.hpp"

Button::Button(float x0, float y0, float width, float height,
               const std::string &text, Color normalColor, Color hoverColor,
               Color clickedColor, Texture2D *texture)
    : _body{x0, y0, width, height}, _design(texture), _normalColor(normalColor),
      _hoveredColor(hoverColor), _clickedColor(clickedColor), _text(text) {};

Rectangle Button::getRectangle() const { return _body; }
Texture2D *Button::getTexture() const { return _design; }
Color Button::getNormalColor() const { return _normalColor; }
Color Button::getHoverColor() const { return _hoveredColor; }
Color Button::getClickedColor() const { return _clickedColor; }
std::string Button::getText() const { return _text; }

Color Button::getActualColor() const {
  if (isClicked())
    return _clickedColor;
  else if (isHovered())
    return _hoveredColor;
  else
    return _normalColor;
}
void Button::setColors(Color normalColor, Color hoverColor, Color clickColor) {
  _normalColor = normalColor;
  _hoveredColor = hoverColor;
  _clickedColor = clickColor;
}
void Button::setTexture(Texture2D *texture) {
  if (texture)
    _design = texture;
}
void Button::setPosition(float x, float y) {
  _body.x = x;
  _body.y = y;
}
void Button::setSize(float width, float height) {
  _body.width = width;
  _body.height = height;
}

void Button::setText(const std::string &text) { _text = text; }

bool Button::isHovered() const {
  return CheckCollisionPointRec(GetMousePosition(), _body);
}
bool Button::isClicked() const {
  return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isHovered() &&
         !IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}
void Button::drawButton() const {
  if (_design) {
    Rectangle sourceRect;
    Vector2 origin = {_body.x, _body.y};

    sourceRect.x = 0.0f;
    sourceRect.y = 0.0f;
    sourceRect.width = _design->width;
    sourceRect.height = _design->height;

    DrawTexturePro(*_design, sourceRect, _body, origin, 0.0f, WHITE);
  } else {
    DrawRectangleRec(_body, getActualColor());
    drawText();
  }
}

void Button::drawText() const {
  DrawText(_text.c_str(), _body.x + 10, _body.y + 10, 12, BLACK);
}
