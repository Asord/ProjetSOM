#pragma once

#include <QObject>
#include "Elements.h"
#include "Settings.h"
#include "Vector.h"
#include "Network.h"

namespace SOM
{
	struct ThreadedCalcsParam
	{
		Network* nwk_ptr;
		Elements* rsc_ptr;
		Settings* stg_ptr;

		int max_it_int;
	};

	class ThreadedCalcs : public QObject
	{
		Q_OBJECT
	public:
		enum DistanceMetric { EUCL };

	private:
		Network* m_pNetwork;
		Elements* m_pResources;
		Settings* m_pSettings;
		Vector m_vWinner;

		int m_nMaxIteration;
		int m_nCurrentIteration;

		double m_fAlpha;
		double m_fBeta;

	public:
		ThreadedCalcs(ThreadedCalcsParam param, QObject *parent = Q_NULLPTR);


	public:

		void SetWinner(QImage& image);
		double GetActivity(uint row, uint col, QImage& image);
		void UpdateWeight(QImage& image);
		void UpdatePhi(Vector& vNeuron);

		double GetDistance(Vector & vNeuron);
		int GetCurrentIteration();

	public slots:
		void process();

	signals:
		void finished();
	};
}
