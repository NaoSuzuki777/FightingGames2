#include "HandlerWaltan.h"



int main()
{
	//�����C�u�����ŕK�{�̃I�u�W�F�N�g
	HandlerWaltan& handlerWaltan = HandlerWaltan::Instance();

	//gameObject�̐���
	unique_ptr<MyGameObject> obj = make_unique<MyGameObject>();

	//MyTransform�R���|�[�l���g��V���ɃA�^�b�`����
	obj->AddMyComponent(make_unique<MyTransform>());
	//MyTransform�̃R���|�[�l���g���擾����
	MyTransform* transform = obj->GetMyComponent<MyTransform>();

	transform->Position = { -1, -2, -3 };

	cout << "\n\n";

	return 0;
}