#include "fcpdrc/cesgrouprecord.hpp"

FcpDRC::cesgrouprecord::cesgrouprecord()
{
        // Initialize member variables
        m_name = QString();
        m_selectedNetGroups = QStringList();
        m_selectedNets = QStringList();
        m_columnHeaders = QStringList();
        m_columnColors = QList<QColor>();
}

void FcpDRC::cesgrouprecord::setName(const QString &name)
{
        m_name = name;
}

void FcpDRC::cesgrouprecord::setSelectedNetGroups(const QStringList &selectedNetGroups)
{
        m_selectedNetGroups = selectedNetGroups;
}

void FcpDRC::cesgrouprecord::setSelectedNets(const QStringList &selectedNets)
{
        m_selectedNets = selectedNets;
}

void FcpDRC::cesgrouprecord::setColumnHeaders(const QStringList &headers)
{
        m_columnHeaders = headers;
}

void FcpDRC::cesgrouprecord::setColumnColors(const QList<QColor> &colors)
{
        m_columnColors = colors;
}

QString FcpDRC::cesgrouprecord::getName() const
{
        return m_name;
}

QStringList FcpDRC::cesgrouprecord::getSelectedNetGroups() const
{
        return m_selectedNetGroups;
}

QStringList FcpDRC::cesgrouprecord::getSelectedNets() const
{
        return m_selectedNets;
}

QStringList FcpDRC::cesgrouprecord::getColumnHeaders() const
{
        return m_columnHeaders;
}

QList<QColor> FcpDRC::cesgrouprecord::getColumnColors() const
{
        return m_columnColors;
}
