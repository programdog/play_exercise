struct ring_buffer {
	int in; /*写指针*/
	int out; /*读指针*/
	int size;  /*环形缓冲区大小*/
	char *buf; /*环形缓冲区*/
};

//初始化Ring Buffer的接口：
bool RingBufferInit(struct ring_buffer *ring_buffer_p, int buf_size)
{
	ring_buffer_p->buf = (char *)malloc(buf_size);
	if (ring_buffer_p->buf)
	{
		memset(fifo_p->buf, 0, buf_size);
	}
	else
	{
		return false;
	}

	ring_buffer_p->size = buf_size;
	ring_buffer_p->head = 0;
	ring_buffer_p->tail = 0;
	return true;
}

//判断Ring Buffer是否为空的接口：

bool RingBufferEmpty(struct ring_buffer *ring_buffer_p)
{
	return (ring_buffer_p->in == ring_buffer_p->out);
}

//判断Ring Buffer是否为满的接口：

bool RingBufferFull(struct ring_buffer *ring_buffer_p)
{
	return (((ring_buffer_p->in) % ring_buffer_p->size) == ring_buffer_p->out);
}

//读取Ring Buffer数据长度的接口：

int GetRingBufferLen(struct ring_buffer *ring_buffer_p)
{
	return ((ring_buffer_p->in - ring_buffer_p->out + ring_buffer_p->size) % ring_buffer_p->size);
}

//清空Ring Buffer的接口：

void RingBufferClear(struct ring_buffer *ring_buffer_p)
{
	ring_buffer_p->in = 0;
	ring_buffer_p->out = 0;
}

//释放Ring Buffer的接口：

void RingBufferClear(struct ring_buffer *ring_buffer_p)
{
	ring_buffer_p->in = 0;
	ring_buffer_p->out = 0;
	ring_buffer_p->size = 0;

	if (ring_buffer_p->buf)
	{
		free(ring_buffer_p->buf);
		ring_buffer_p->buf = NULL;
	}
}

//向Ring Buffer的写数据接口：

int RingBufferPut(struct ring_buffer *ring_buffer_p, char *buf, int len)
{
	int real_in_len = 0 , i = 0, surplus_buf_len = 0;

	if (len >= ring_buffer_p->size)
	{
		return -1;
	}

	surplus_buf_len = ring_buffer_p->size - GetRingBufferLen(ring_buffer_p);
	if (len > surplus_buf_len)
	{
		real_in_len = surplus_buf_len;
	}
	else if (len <= surplus_buf_len)
	{
		real_in_len = len;
	}

	for (i = 0; i < real_in_len; i ++)
	{
		ring_buffer_p->buf[ring_buffer_p->in % ring_buffer_p->size] = buf[i];
		ring_buffer_p->in = (ring_buffer_p->in + 1) % ring_buffer_p->size;
	}

	return i;
}

//读取Ring Buffer数据的接口：

int RingBufferGet(struct ring_buffer *ring_buffer_p, char *buf, int buf_len)
{
	hd_s32_t real_out_len = 0, i =0, data_len = 0;

	data_len = GetRingBufferLen(ring_buffer_p);
	if (buf_len > data_len)
	{
		real_out_len = data_len;
	}
	else if ( buf_len <= data_len)
	{
		real_out_len = buf_len;
	}

	for (i = 0; i < real_out_len; i ++)
	{
		buf[i] = ring_buffer_p->buf[ring_buffer_p->out % ring_buffer_p->size];
		ring_buffer_p->out = (ring_buffer_p->out + 1) % ring_buffer_p->size;
	}

	return i;
}
