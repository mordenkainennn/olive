/***

    Olive - Non-Linear Video Editor
    Copyright (C) 2019  Olive Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef TEXTEDITDIALOG_H
#define TEXTEDITDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QFontComboBox>

#include "ui/labelslider.h"
#include "ui/colorbutton.h"

class TextEditDialog : public QDialog {
  Q_OBJECT
public:
  TextEditDialog(QWidget* parent = nullptr, const QString& s = nullptr, bool rich_text = true);
  const QString& get_string();
signals:
  void cursorPositionChanged();
private slots:
  void save();
  void cancel();

  void SetBold(bool bold);
  void SetFontWeight(int i);
  void SetLetterSpacing(qreal spacing);
  void SetAlignmentFromProperty();
  void UpdateUIFromTextCursor();
private:
  bool rich_text_;

  QString result_str;
  QTextEdit* textEdit;
  QPushButton* italic_button;
  QPushButton* underline_button;
  QFontComboBox* font_list;
  QComboBox* font_weight;
  LabelSlider* font_size;
  ColorButton* font_color;
  QPushButton* left_align_button;
  QPushButton* center_align_button;
  QPushButton* right_align_button;
  QPushButton* justify_align_button;
};

#endif // TEXTEDITDIALOG_H
