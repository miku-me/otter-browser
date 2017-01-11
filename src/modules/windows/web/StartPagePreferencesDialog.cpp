/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2015 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
* Copyright (C) 2016 Piotr Wójcik <chocimier@tlen.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#include "StartPagePreferencesDialog.h"
#include "../../../core/SettingsManager.h"

#include "ui_StartPagePreferencesDialog.h"

#include <QtWidgets/QPushButton>

namespace Otter
{

StartPagePreferencesDialog::StartPagePreferencesDialog(QWidget *parent) : Dialog(parent),
	m_ui(new Ui::StartPagePreferencesDialog)
{
	m_ui->setupUi(this);

	const QString backgroundModeString(SettingsManager::getValue(SettingsManager::StartPage_BackgroundModeOption).toString());

	m_ui->customBackgroundCheckBox->setChecked(backgroundModeString != QLatin1String("standard"));
	m_ui->backgroundFilePathWidget->setPath(SettingsManager::getValue(SettingsManager::StartPage_BackgroundPathOption).toString());
	m_ui->backgroundFilePathWidget->setFilters(QStringList(tr("Images (*.png *.jpg *.bmp *.gif)")));
	m_ui->backgroundModeComboBox->addItem(tr("Best fit"), QLatin1String("bestFit"));
	m_ui->backgroundModeComboBox->addItem(tr("Center"), QLatin1String("center"));
	m_ui->backgroundModeComboBox->addItem(tr("Stretch"), QLatin1String("stretch"));
	m_ui->backgroundModeComboBox->addItem(tr("Tile"), QLatin1String("tile"));
	m_ui->backgroundColorWidget->setColor(SettingsManager::getValue(SettingsManager::StartPage_BackgroundColorOption).toString());

	const int backgroundModeIndex(m_ui->backgroundModeComboBox->findData(backgroundModeString));

	m_ui->backgroundModeComboBox->setCurrentIndex((backgroundModeIndex < 0) ? 0 : backgroundModeIndex);
	m_ui->backgroundWidget->setEnabled(m_ui->customBackgroundCheckBox->isChecked());
	m_ui->columnsPerRowSpinBox->setValue(SettingsManager::getValue(SettingsManager::StartPage_TilesPerRowOption).toInt());
	m_ui->zoomLevelSpinBox->setValue(SettingsManager::getValue(SettingsManager::StartPage_ZoomLevelOption).toInt());
	m_ui->showSearchFieldCheckBox->setChecked(SettingsManager::getValue(SettingsManager::StartPage_ShowSearchFieldOption).toBool());
	m_ui->showAddTileCheckBox->setChecked(SettingsManager::getValue(SettingsManager::StartPage_ShowAddTileOption).toBool());

	connect(this, SIGNAL(accepted()), this, SLOT(save()));
	connect(m_ui->customBackgroundCheckBox, SIGNAL(toggled(bool)), m_ui->backgroundWidget, SLOT(setEnabled(bool)));
	connect(m_ui->buttonBox->button(QDialogButtonBox::Apply), SIGNAL(clicked()), this, SLOT(save()));
}

StartPagePreferencesDialog::~StartPagePreferencesDialog()
{
	delete m_ui;
}

void StartPagePreferencesDialog::changeEvent(QEvent *event)
{
	QDialog::changeEvent(event);

	if (event->type() == QEvent::LanguageChange)
	{
		m_ui->retranslateUi(this);
	}
}

void StartPagePreferencesDialog::save()
{
	const QString backgroundModeString(m_ui->backgroundModeComboBox->currentData().toString());

	SettingsManager::setValue(SettingsManager::StartPage_BackgroundColorOption, (m_ui->backgroundColorWidget->getColor().isValid() ? m_ui->backgroundColorWidget->getColor().name() : QString()));
	SettingsManager::setValue(SettingsManager::StartPage_BackgroundModeOption, (m_ui->customBackgroundCheckBox->isChecked() ? backgroundModeString : QLatin1String("standard")));
	SettingsManager::setValue(SettingsManager::StartPage_BackgroundPathOption, m_ui->backgroundFilePathWidget->getPath());
	SettingsManager::setValue(SettingsManager::StartPage_TilesPerRowOption, m_ui->columnsPerRowSpinBox->value());
	SettingsManager::setValue(SettingsManager::StartPage_ZoomLevelOption, m_ui->zoomLevelSpinBox->value());
	SettingsManager::setValue(SettingsManager::StartPage_ShowSearchFieldOption, m_ui->showSearchFieldCheckBox->isChecked());
	SettingsManager::setValue(SettingsManager::StartPage_ShowAddTileOption, m_ui->showAddTileCheckBox->isChecked());
}

}
