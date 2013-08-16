#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class HelloW : public QWidget {
Q_OBJECT
public:
  HelloW();

public slots:
  void button_click();

signals:
  void clicked();

private:
  QLabel* l;
  QPushButton* b;
  QVBoxLayout* vbl;
};
