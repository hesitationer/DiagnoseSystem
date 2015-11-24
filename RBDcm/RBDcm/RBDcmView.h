/**********************************************************************************
  Copyright @ Robin 2015-2025
  File name:  RBDcmView.h
  Author: Robin   Version: V1.0   Date: 2015.11.05 
  Description: Software Frame  View Class 
               This class contain main View and image layers manage
  Others:         
***********************************************************************************/
#pragma once
#include "RBDcmDoc.h"
#include <afxtempl.h>
#include "Layer.h"
#include "RBMermoryDC.h"
#include "ImgLayer.h"

class COprtView;

class CRBDcmView : public CView
{
private:
	UINT m_nType;                     //���Ƶ�ͼ������
	CArray <CLayer*, CLayer*> m_ls;   //��¼����ͼ�����ļ���
	CPoint m_ptStart;                 //�϶�ʱͼ�����
	CPoint m_ptEnd;                   //�϶�ʱͼ���յ�
	sOneImg m_sOneImgShow;            //��ʾ��ͼ������
protected: // �������л�����
	CRBDcmView();
	DECLARE_DYNCREATE(CRBDcmView)
public:
	CRBDcmDoc* GetDocument() const;
public:
	virtual void OnDraw(CDC* pDC);			// ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

public:
	virtual ~CRBDcmView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	void ReDraw(void);
	bool isMax;
	void SetImgData(sOneImg src);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

#ifndef _DEBUG  // RBDcmView.cpp �еĵ��԰汾
inline CRBDcmDoc* CRBDcmView::GetDocument() const
   { return reinterpret_cast<CRBDcmDoc*>(m_pDocument); }
#endif
