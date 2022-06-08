
// Demo2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Demo2.h"
#include "Demo2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CDemo2Dlg



CDemo2Dlg::CDemo2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEMO2_DIALOG, pParent)
	, m_ctrlPathInfo(_T(""))
	, m_ctrlPathEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemo2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PATH_INFO, m_ctrlPathInfo);
	DDX_Text(pDX, IDC_EDIT_BROWSE, m_ctrlPathEdit);
	DDX_Control(pDX, IDC_TREE1, m_ctrlTree);
}

BEGIN_MESSAGE_MAP(CDemo2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_UPDATE(IDC_EDIT_BROWSE, &CDemo2Dlg::OnUpdateEditBrowse)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &CDemo2Dlg::OnNMDblclkTree1)
END_MESSAGE_MAP()


// Обработчики сообщений CDemo2Dlg

BOOL CDemo2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CDemo2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CDemo2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CDemo2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//--------------------Реализация тестового задания-------------------

// Функция избавляет объект класса string от пробелов по бокам 
void Trim(std::string& word_to_clear) {
	size_t start = word_to_clear.find_first_not_of(" ");
	size_t end = word_to_clear.find_last_not_of(" ");
	word_to_clear = word_to_clear.substr(start, end - start + 1);
}

// Функция выделяет необходимый для добавления элемент из строки
std::string ParseInformation(std::string& info_to_parse) {
	size_t start = info_to_parse.find_first_of(":");
	std::string result = info_to_parse.substr(0, start);
	info_to_parse = info_to_parse.substr(start+1);
	Trim(result);
	return result;
}

// Функция создает объекты класса TreeNode
TreeNode MakeNodeFromString(std::string& node_info) {
	TreeNode result;
	result.id = stoi(ParseInformation(node_info));
	result.pid = stoi(ParseInformation(node_info));
	result.caption = ParseInformation(node_info);
	result.status = stoi(ParseInformation(node_info));
	result.message = ParseInformation(node_info);
	return result;

}

// Функция добавляет объекты класса TreeNode в контейнеры nodes_ и nodes_id
void CDemo2Dlg::AddNode(std::string node_info) {
	TreeNode* it = &nodes_.emplace_front(MakeNodeFromString(std::move(node_info)));// Стандарт С++17
	if (nodes_id.count(it->id) == 0) {
		nodes_id[it->id] = it;
	}
}

// Функция получает доступ к текстовому файлу, по заранее полученному пути.
// После получения доступа к файлу, начинается построчное считывание файла
// и создание объектов класса TreeNode
bool CDemo2Dlg::LoadInfoFromFile(std::string path_) {
	using namespace std;
	ifstream in (path_);
	string buffer;
	int numb = 0;
	while (getline(in, buffer)) {
		
		numb = std::count(buffer.begin(), buffer.end(), ':');
		if (numb == 4) {
			Trim(buffer);
			AddNode(std::move(buffer));
		}
		else {
			return false;
		}
	}
	return true;
}

// Рекурсивная функция на случай, если нода объявлена раньше родителя
bool CDemo2Dlg::AddSingleTreeNode(int node_id) {
	TreeNode& node = *nodes_id.at(node_id);
	CA2T wt(node.caption.c_str());
	if (nodes_id.count(node.pid) != 0 && tree_on_dial_.count(node.pid) == 0) {
		if (!AddSingleTreeNode(node.pid)) {
			return false;
		}
		else {
			if (node.pid == -1) {
				tree_on_dial_[node_id] = m_ctrlTree.InsertItem(wt, TVI_ROOT, TVI_SORT);
				point_to_tree_[tree_on_dial_.at(node_id)] = node_id;
			}
			else {
				tree_on_dial_[node_id] = m_ctrlTree.InsertItem(wt,
					tree_on_dial_[node.pid],
					TVI_SORT);
				point_to_tree_[tree_on_dial_.at(node_id)] = node_id;
			}
		}
	}
	else if (nodes_id.count(node.pid) != 0 && tree_on_dial_.count(node.pid) != 0) {
		if (node.pid == -1) {
			tree_on_dial_[node_id] = m_ctrlTree.InsertItem(wt, TVI_ROOT, TVI_SORT);
			point_to_tree_[tree_on_dial_.at(node_id)] = node_id;
		}
		else {
			tree_on_dial_[node_id] = m_ctrlTree.InsertItem(wt,
				tree_on_dial_[node.pid],
				TVI_SORT);
			point_to_tree_[tree_on_dial_.at(node_id)] = node_id;
		}
	}
	else if (nodes_id.count(node.pid) == 0) {
		return false;
	}

	return true;
}

// Функция создает элементы дерева в оконном приложении.
// Если родительский класс равен -1, то элемент находится в корне
bool CDemo2Dlg::MakeTreeOnInitDialog() {
	for (auto [id, tree] : nodes_id) {
		CA2T wt(tree->caption.c_str());
		if (tree->pid == -1) {// Если родитель ноды имеет id = -1, то создается корневой объект
			tree_on_dial_[id] = m_ctrlTree.InsertItem(wt, TVI_ROOT, TVI_SORT);
			point_to_tree_[tree_on_dial_.at(id)] = id;
		}
		else {
			if (nodes_id.count(tree->pid) == 0) {// Если родительской ноды нет среди всех созданных объектов класса TreeNode, функция завершается
				return false;
			}
			else if (tree_on_dial_.count(tree->pid) == 0) {// Если родитель еще не добавлен в Tree Control, то запускаем рекурсивную функцию
				if (!AddSingleTreeNode(id)) {// Если рекурсией не получилось найти родителя, то прекращаем работу функции и выводим ошибку
					return false;
				}
			}
			else if (tree_on_dial_.count(id) == 0 && tree_on_dial_.count(tree->pid) != 0) {// Если нода еще не добавлена в Tree Control, а родитель создан, создаем ноду
				tree_on_dial_[id] = m_ctrlTree.InsertItem(wt,
					tree_on_dial_[tree->pid],
					TVI_SORT);
				point_to_tree_[tree_on_dial_.at(id)] = id;
			}
		}
	}
	return true;
}

// Функция вызывается при выборе пути в окне EditBrowseControl,
// после чего читает выбранный файл и создает объекты класса TreeNode,
// описанные в TreeNode.h. Последний этап работы функции - заполнение
// элемента TreeControl в оконном приложении
void CDemo2Dlg::OnUpdateEditBrowse()
{
	UpdateData(TRUE);
	std::string out;
	out = CT2CA(m_ctrlPathEdit.GetBuffer(0));

	
	if (LoadInfoFromFile(out)) {
		if (!MakeTreeOnInitDialog()) {
			m_ctrlPathInfo = L" Ошибка - Неcуществующий родительский id";
		}
		else {
			m_ctrlPathInfo = L"Успешно!";
		}
	}
	else {
		m_ctrlPathInfo = L" Ошибка - Некорректный формат входных данных";
	}
	UpdateData(FALSE);

}

// Функция вызывается при двойном клике на элемент дерева
// и вызывает MessageBox с полем message соответствующей ноды
void CDemo2Dlg::OnNMDblclkTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	HTREEITEM selectNode = (m_ctrlTree.GetSelectedItem());
	if (selectNode == NULL) {
		return;
	}
	CA2T out = nodes_id.at(point_to_tree_.at(selectNode))->message.c_str();
	MessageBox(out);
}
