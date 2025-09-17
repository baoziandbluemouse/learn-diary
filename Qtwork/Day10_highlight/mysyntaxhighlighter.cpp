#include "mysyntaxhighlighter.h"
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent):QSyntaxHighlighter(parent)
{

}

MySyntaxHighlighter::~MySyntaxHighlighter()
{

}

void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat myFormat;

    myFormat.setFont(QFont("微软雅黑"));

    myFormat.setFontWeight(QFont::Bold);

    myFormat.setForeground(Qt::green);

    //匹配char
    QString pattern = "\\bchar\\b";

    QRegularExpression exp(pattern);
    QRegularExpressionMatch match = exp.match(text); //更正拼写

    int idx = match.capturedStart(); // 获取匹配的起始位置

    // 使用 while 循环查找所有匹配项

    while (idx >= 0){
        int len = match.capturedLength();
        // 获取匹配的长度

        // 应用格式到匹配的文本
        setFormat(idx, len, myFormat);

        // 查找下一个匹配项
        match = exp.match(text, idx + len);
        idx=match.capturedStart();
    }


}
