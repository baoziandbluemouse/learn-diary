#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextDocument>

class MySyntaxHighlighter:public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument * parent = 0);
    ~MySyntaxHighlighter();
    //重新实现高亮
protected:
    virtual void highlightBlock(const QString& text);
};

#endif // MYSYNTAXHIGHLIGHTER_H
