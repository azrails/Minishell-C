#include "../../include/minishell.h"

void		change_env(t_env *current_env, t_env *env)
{
	if (current_env->value && env->value == NULL)
		free(env->value);
	else
	{
		free(current_env->value);
		current_env->value = env->value;
	}
	free(env->key);
	free(env);
}

void		sort_env(t_list *first_elem, t_list *second_elem, t_list *temp_elem)
{
	void	*temp_content;

	if (temp_elem)
		first_elem->next->next = temp_elem;
	temp_content = first_elem->content;
	first_elem->content = second_elem->content;
	second_elem->content = temp_content;
}

t_env		*init_env(char **key_value)
{
	t_env	*env;

	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	env->key = key_value[0];
	env->value = key_value[1];
	return (env);
}

void		add_env(t_list *env_list, t_env *env)
{
	int		cmp;
	t_list	*temp_elem;
	t_env	*current_env;

	while (env_list)
	{
		current_env = (t_env*)env_list->content;
		cmp = compare_str(env->key, current_env->key);
		if (cmp <= 0 || env_list->next == NULL)
		{
			if (cmp < 0)
			{
				temp_elem = env_list->next;
				env_list->next = ft_lstnew(env);
				sort_env(env_list, env_list->next, temp_elem);
			}
			else if (cmp == 0)
				change_env(current_env, env);
			else
				env_list->next = ft_lstnew(env);
			break ;
		}
		env_list = env_list->next;
	}
}

char		**list_to_array(t_list *list)
{
	char	**array;
	char	*tmp;
	t_env	*env;
	int		size;
	int		i;

	size = ft_lstsize(list);
	i = 0;
	if (!(array = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (list)
	{
		env = list->content;
		if (env->value && *env->value)
		{
			tmp = ft_strjoin(env->key, "=");
			array[i++] = ft_strjoin(tmp, env->value);
			free(tmp);
		}
		list = list->next;
	}
	array[i] = NULL;
	return (array);
}
