#ifndef CESGROUPRECORD_H
#define CESGROUPRECORD_H
#include "QString"
#include "QStringList"
#include "qcolor.h"
#include <QtNodes/internal/Export.hpp>

namespace FcpDRC
{

class NODE_EDITOR_PUBLIC cesgrouprecord
{
      public:
        cesgrouprecord();
        void setName(const QString &name);
        void setSelectedNetGroups(const QStringList &selectedNetGroups);
        void setSelectedNets(const QStringList &selectedNets);
        void setColumnHeaders(const QStringList &headers);
        void setColumnColors(const QList<QColor> &colors);

        QString getName() const;
        QStringList getSelectedNetGroups() const;
        QStringList getSelectedNets() const;
        QStringList getColumnHeaders() const;
        QList<QColor> getColumnColors() const;

      private:
        QString m_name;
        QStringList m_selectedNetGroups;
        QStringList m_selectedNets;
        QStringList m_columnHeaders;
        QList<QColor> m_columnColors;
};

} // namespace FcpDRC

#endif // CESGROUPRECORD_H
