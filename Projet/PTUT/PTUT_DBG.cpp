#include "PTUT.h"


namespace SOM
{
    void PTUT::drawInput()
    {
        m_pEntryScene = new QGraphicsScene(this);
        ui.graphicsPreview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui.graphicsPreview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        QPen outlinePen(Qt::black);
        outlinePen.setWidth(0);

        for (uint i = 0;  i < network->m_resources.m_nHeight * network->m_resources.m_nWidth; ++i)
        {
            uint col = i % network->m_resources.m_nWidth;
            uint row = i / network->m_resources.m_nWidth;

            Color color = network->m_resources.m_fColor[i];
            uchar red = color[0];
            uchar gre = color[1];
            uchar blu = color[2];

            QBrush brush(QColor(red, gre, blu));
            m_pEntryScene->addRect(
            (ui.graphicsPreview->width() - 5) / network->m_resources.m_nWidth*col,
            (ui.graphicsPreview->height() - 5) / network->m_resources.m_nHeight*row,
                    ui.graphicsPreview->width() / 10,
            ui.graphicsPreview->height() / 10,
            outlinePen,
            brush
            );
        }
        ui.graphicsPreview->setScene(m_pEntryScene);
        ui.graphicsPreview->update();

    }
}

