#ifndef PEAKDETECTIONDIALOG_H
#define PEAKDETECTIONDIALOG_H

#include "ui_peakdetectiondialog.h"
#include "stable.h"

class MainWindow;
class TableDockWidget;
class BackgroundPeakUpdate;
class PeakDetectionSettings;

class PeakDetectionDialog : public QDialog, public Ui_PeakDetectionDialog
{
		Q_OBJECT

		public:
				 enum FeatureDetectionType { FullSpectrum=0, CompoundDB, QQQ };
				 PeakDetectionDialog(QWidget *parent);
				 ~PeakDetectionDialog();
				 void setSettings(QSettings* settings) { this->settings = settings; }
				 void setMainWindow(MainWindow* w) { this->mainwindow = w; }
                 MainWindow* getMainWindow() {return mainwindow;}
                 void displayAppropriatePeakDetectionDialog(FeatureDetectionType type); //TODO: Sahil - Kiran, Added while merging mainwindow
				 void setMavenParameters(QSettings *settings);

		public Q_SLOTS:
				 void findPeaks();
				 void loadModel();
    void setModel(const QString& modelPath);
                                 void setOutputDir();
				 void setProgressBar(QString text, int progress, int totalSteps);
				 void runBackgroupJob(QString func);
                 void dbOptionsClicked();
                 void featureOptionsClicked();
				 void showInfo(QString text);
				 void cancel();
                 void initPeakDetectionDialogWindow(FeatureDetectionType type);
                 void toggleFragmentation(QString);
				 void showMethodSummary(); //TODO: Sahil - Kiran, Added while merging mainwindow
                 void saveMethod(); //TODO: Sahil - Kiran, Added while merging mainwindow
                 void loadMethod(); //TODO: Sahil - Kiran, Added while merging mainwindow
                 void updatePeakTableList(); //TODO: Sahil - Kiran, Added while merging mainwindow
				 void show(); //TODO: Sahil - Kiran, Added while merging mainwindow
				 void showSettingsForm();
				 void showIntensityQuantileStatus(int);
				 void showQualityQuantileStatus(int);
				 void showBaselineQuantileStatus(int);
				 void showBlankQuantileStatus(int);
                 void setMassCutoffType(QString type);
                virtual void closeEvent(QCloseEvent* event) override;
                                void triggerSettingsUpdate();
                void onReset();

                Q_SIGNALS:
                    void updateSettings(PeakDetectionSettings* pd);
                    void settingsUpdated(QString key, QVariant value);
                    void settingsChanged(string key, string value);
                    void resetSettings(QList<QString> keys);
        public:
                QString massCutoffType;

        private:
				QSettings *settings;
				MainWindow *mainwindow;
                BackgroundPeakUpdate* peakupdater;
				FeatureDetectionType _featureDetectionType;
                PeakDetectionSettings* peakSettings;

                // void displayAppropriatePeakDetectionDialog(FeatureDetectionType type); //TODO: Sahil - Kiran, removed while merging mainwindow
                void inputInitialValuesPeakDetectionDialog();
                void updateQSettingsWithUserInput(QSettings *settings);


};

Q_DECLARE_METATYPE(QString*)

class PeakDetectionSettings: public QObject
{
    Q_OBJECT
    public:
        PeakDetectionSettings(PeakDetectionDialog* dialog);
        QMap<QString,QVariant>& getSettings() { return settings; }

    public Q_SLOTS:
        void updatePeakSettings(string key, string value);

    private:
        QMap<QString, QVariant> settings;
        PeakDetectionDialog* pd;

};

#endif
